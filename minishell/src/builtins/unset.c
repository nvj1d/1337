/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:47:07 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:20:21 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	del_lst_env_elem(t_environment_list *environment_list)
{
	free(environment_list->key);
	if (environment_list->val)
		free(environment_list->val);
	free (environment_list);
}

void	lst_env_pop(t_environment_list **list, char *key)
{
	t_environment_list	*temp;
	t_environment_list	*prev;

	prev = *list;
	if (!ft_strcmp((*list)->key, key))
	{
		(*list) = (*list)->next;
		del_lst_env_elem(prev);
		return ;
	}
	prev = *list;
	temp = (*list)->next;
	while (temp)
	{
		if (!ft_strcmp(temp->key, key))
		{
			prev->next = temp->next;
			del_lst_env_elem(temp);
			return ;
		}
		prev = temp;
		temp = temp->next;
	}
}

int	valid_unset(char *arg)
{
	int	i;

	i = 0;
	if (!ft_isalpha(arg[0]))
		return (0);
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

void	unset(void)
{
	int		i;
	char	**args;

	i = 0;
	args = g_shell.command_list->args;
	g_shell.status = 0;
	while (args[i])
	{
		if (!valid_unset(args[i]))
		{
			ft_putendl_fd("not a valid identifier", STDERR_FILENO);
			g_shell.status = 1;
		}
		else
		{
			lst_env_pop(&g_shell.environment_list, args[i]);
			if (g_shell.env)
			{
				memclean(g_shell.env, len_2d_str(g_shell.env));
				g_shell.env = collect_env(g_shell.environment_list);
			}
		}
		i++;
	}
}
