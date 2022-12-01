/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:46:54 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:19:31 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_key(char *var)
{
	int	i;

	i = 0;
	if (!ft_strchr(var, '='))
		return (ft_strdup(var));
	while (var[i] != '=')
		i++;
	return (ft_substr(var, 0, i));
}

int	try_change_val(t_environment_list *environment_list, t_environment_list *elem)
{
	while (environment_list)
	{
		if (!ft_strcmp(environment_list->key, elem->key))
		{
			if (!elem->equal || (environment_list->val && elem->val
					&& !ft_strcmp(elem->val, environment_list->val)))
				return (1);
			if (environment_list->val)
				free(environment_list->val);
			environment_list->val = NULL;
			environment_list->equal = 0;
			if (elem->val)
			{
				environment_list->val = ft_strdup(elem->val);
				if (NULL == environment_list->val)
					exit_with_error("minishell: -: malloc error");
				environment_list->equal = 1;
			}
			return (1);
		}
		environment_list = environment_list->next;
	}
	return (0);
}

void	change_env_val(t_environment_list *elem, t_environment_list **environment_list)
{
	char	*val;

	if (!try_change_val(*environment_list, elem))
	{
		if (elem->val)
			val = ft_strdup(elem->val);
		else
			val = NULL;
		lst_envadd_back(environment_list,
			lst_envnew(ft_strdup(elem->key), val));
	}
	if (g_shell.env)
	{
		memclean(g_shell.env, len_2d_str(g_shell.env));
		g_shell.env = collect_env(g_shell.environment_list);
	}
	del_lst_env_elem(elem);
}

void	print_export(t_environment_list *environment_list)
{
	t_environment_list	*export;

	export = cp_env(environment_list);
	print_environment_list(export, EXPORT_MODE);
	clean_environment_list(export);
}

void	export(void)
{
	int			i;
	t_environment_list	*elem;
	int			len;
	char		**args;

	i = 0;
	args = g_shell.command_list->args;
	len = len_2d_str(args);
	if (1 == len)
		print_export(g_shell.environment_list);
	while (len > 1 && args[++i])
	{
		if (!valid_export(args[i]))
			return ;
		else
		{
			elem = get_env_elem(args[i]);
			if (!elem)
				exit_with_error("minishell: -: malloc error");
			change_env_val(elem, &g_shell.environment_list);
		}
	}
}
