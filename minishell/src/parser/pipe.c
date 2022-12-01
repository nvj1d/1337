/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:46:10 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:20:53 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**command_split(char *str, int i, int j, int h)
{
	char	**cmds;

	cmds = ft_calloc(sizeof(char *), 100);
	while (str[++i])
	{
		j = i;
		while (str[i] && str[i] != ' ' && str[i] != '\'' && \
		str[i] != '\"' && str[i] != '>' && str[i] != '<')
			i++;
		if ((str[i] == ' ' || str[i] == '\0' || \
		str[i] == '>' || str[i] == '<') && j != i)
		{
			cmds[h++] = ft_substr(str, j, i - j);
			if (str[i] == '\0')
				break ;
		}
		if (str[i] == '\'' || str[i] == '\"')
			cmds[h++] = get_cmds(str, &i, j);
		if (str[i] == '>' || str[i] == '<')
			cmds[h++] = get_redir(str, &i, str[i]);
	}
	free(str);
	return (cmds);
}

void	clear_list(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

int	check_redir_cmd(char *cmd)
{
	if ((ft_strncmp(cmd, ">", 1) == 0 && \
		ft_strlen(cmd) == 1) || \
		(ft_strncmp(cmd, ">>", 2) == 0 && \
		ft_strlen(cmd) == 2) || \
		(ft_strncmp(cmd, "<", 1) == 0 && \
		ft_strlen(cmd) == 1) || \
		(ft_strncmp(cmd, "<<", 2) == 0 && ft_strlen(cmd) == 2))
		return (1);
	return (0);
}

int	check_redir(char *str, int i)
{
	int		j;
	char	ch;

	j = -1;
	if (str[0] == '>' || str[0] == '<')
		return (1);
	while (++j < i)
	{
		if (str[j] == '\'' || str[j] == '\"')
		{
			ch = str[j];
			while (str[++j] && str[j] != ch)
				;
		}
		if (str[j] == '>' || str[j] == '<')
			return (j);
	}
	return (0);
}

char	*pipe_parse(int *i, char *str, int j, int k)
{
	char	**temp_cmd;
	char	**cmd;
	char	*ret;

	temp_cmd = command_split(ft_substr(str, 0, *i), -1, 0, 0);
	ret = ft_substr(str, *i + 1, ft_strlen(str));
	cmd = ft_calloc(sizeof(char *), 100);
	while (temp_cmd[j])
	{
		if (check_redir_cmd(temp_cmd[j]))
			j++;
		else
			cmd[k++] = ft_strdup(temp_cmd[j]);
		j++;
	}
	ft_lstadd_back_parse(&g_shell.command_list, ft_lstnew_parse(cmd));
	if (check_redir(str, *i))
		redir(temp_cmd, -1);
	free(str);
	clear_list(temp_cmd);
	*i = 0;
	return (ret);
}
