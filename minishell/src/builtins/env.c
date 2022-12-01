/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:46:46 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:19:19 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	memclean(char **s, size_t l)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (i < l)
		{
			free(s[i]);
			i++;
		}
		free(s);
	}
}

char	*get_env(char *key, t_environment_list *environment_list)
{
	while (environment_list)
	{
		if (!ft_strcmp(key, environment_list->key) && environment_list->equal)
			return (environment_list->val);
		environment_list = environment_list->next;
	}
	return (NULL);
}

void	print_environment_list(t_environment_list *environment_list, int flag)
{
	while (environment_list)
	{
		if (EXPORT_MODE == flag)
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
		if (!environment_list->equal && ENV_MODE == flag)
		{
			environment_list = environment_list->next;
			continue ;
		}
		ft_putstr_fd(environment_list->key, 1);
		if (environment_list->equal)
		{
			ft_putstr_fd("=", STDOUT_FILENO);
			if (EXPORT_MODE == flag)
				ft_putchar_fd('\"', STDOUT_FILENO);
			if (environment_list->val)
				ft_putstr_fd(environment_list->val, STDOUT_FILENO);
			if (EXPORT_MODE == flag)
				ft_putchar_fd('\"', STDOUT_FILENO);
		}
		ft_putendl_fd("", STDOUT_FILENO);
		environment_list = environment_list->next;
	}
}

void	env(void)
{
	g_shell.status = 0;
	print_environment_list(g_shell.environment_list, ENV_MODE);
}
