/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:46:02 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:15:27 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_pipe(int i)
{
	while (g_shell.command_list)
	{
		if (i == 0 && g_shell.command_list->next)
		{
			g_shell.command_list->pipe_in = default_pipe_in;
			g_shell.command_list->pipe_out = pipe_out;
		}
		if (i > 0 && g_shell.command_list->next)
		{
			g_shell.command_list->pipe_in = pipe_in;
			g_shell.command_list->pipe_out = pipe_out;
		}
		if (i > 0 && !g_shell.command_list->next)
		{
			g_shell.command_list->pipe_in = pipe_in;
			g_shell.command_list->pipe_out = default_pipe_out;
		}
		i++;
		g_shell.command_list = g_shell.command_list->next;
	}
}

void	check_pipe(void)
{
	t_cmd	*temp;

	temp = g_shell.command_list;
	add_pipe(0);
	g_shell.command_list = temp;
}

void	split_cmd(char *str)
{
	int		i;
	char	ch;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			ch = str[i];
			while (str[++i] && str[i] != ch)
				;
		}
		if (str[i] == '|')
			str = pipe_parse(&i, str, 0, 0);
	}
	str = pipe_parse(&i, str, 0, 0);
	free(str);
}

void	*parser(char *str)
{
	if (str == NULL)
	{
		ft_putendl_fd("\033[0;31m Minishell \033[0;32m~$ \033[4;0m exit", 2);
		exit(0);
	}
	if (str && str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	else if (!preparsing(str) || str[0] == '|')
	{
		free(str);
		error_parser("minishell: syntax error near unexpected token");
	}
	else
	{
		str = check_syntax(str, -1, 0);
		split_cmd(str);
		check_pipe();
	}
	return (NULL);
}
