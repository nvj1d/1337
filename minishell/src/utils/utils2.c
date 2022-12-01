/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:15:09 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:15:10 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_redir_list(t_redir *redir)
{
	t_redir	*tmp_list;

	if (redir)
	{
		while (redir)
		{
			tmp_list = redir->next;
			free(redir->filename);
			free(redir);
			redir = tmp_list;
		}
	}	
}

void	clean_command_list(t_cmd *command_list)
{
	t_cmd	*tmp_list;

	if (command_list)
	{
		while (command_list)
		{
			tmp_list = command_list->next;
			clean_redir_list(command_list->redir_in);
			clean_redir_list(command_list->redir_out);
			free(command_list);
			command_list = tmp_list;
		}
	}
	command_list = NULL;
}

void	clean_environment_list(t_environment_list *list)
{
	t_environment_list	*temp_list;

	while (list)
	{
		temp_list = list->next;
		free(list->key);
		if (list->equal)
			free(list->val);
		free (list);
		list = temp_list;
	}
}

void	clear_all(t_minishell *shell)
{
	close(shell->stdout);
	close(shell->stdin);
	clean_command_list(shell->command_list_head);
	clean_environment_list(shell->environment_list);
	memclean(shell->functions_names, len_2d_str(shell->functions_names));
	memclean(shell->env, len_2d_str(shell->env));
}

char	*collect_str_env(t_environment_list *elem)
{
	char	*str;
	char	*temp;

	temp = ft_strjoin (elem->key, "=");
	str = ft_strjoin (temp, elem->val);
	free (temp);
	return (str);
}
