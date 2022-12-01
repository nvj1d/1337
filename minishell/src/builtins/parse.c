/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:47:01 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:19:54 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	add_slash(char ***pathes)
{
	int		i;
	char	*tmp;
	char	**tmp_pathes;

	i = 0;
	tmp_pathes = *pathes;
	while (tmp_pathes[i])
	{
		tmp = tmp_pathes[i];
		tmp_pathes[i] = ft_strjoin(tmp, "/");
		free(tmp);
		if (tmp_pathes[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

static int	set_path(char **cmd, char **pathes)
{
	int		i;
	char	*path;

	i = 0;
	while (pathes[i])
	{
		path = ft_strjoin(pathes[i++], *cmd);
		if (path == NULL)
		{
			memclean(pathes, len_2d_str(pathes));
			exit (1);
		}
		if (!access(path, 0))
		{
			free(*cmd);
			*cmd = path;
			return (1);
		}
		free(path);
	}
	return (-1);
}

static int	get_cmd(char **args, char **pathes)
{
	int	ok;

	if (!ft_strcmp(args[0], ".") || !ft_strcmp(args[0], ".."))
		ok = -1;
	else
		ok = set_path (&args[0], pathes);
	if (ok == 0)
	{
		exit_with_error("minishell: -: malloc error");
	}
	else if (ok == -1)
	{
		print_error(args[0], "command not found");
		g_shell.status = 127;
		ok = 0;
	}
	return (ok);
}

char	**get_pathes(t_environment_list *environment_list)
{
	char	*path;
	char	**pathes;

	path = NULL;
	path = get_env("PATH", environment_list);
	if (path)
	{
		pathes = ft_split(path, ':');
		if (pathes && add_slash(&pathes))
			return (pathes);
	}
	else
	{
		g_shell.status = 127;
		print_error(g_shell.command_list->args[0], "No such file or directory");
	}
	return (NULL);
}

int	parse_cmds(t_cmd *cmd)
{
	int		ret;
	char	**pathes;
	int		ok;

	ok = 1;
	if (!(g_shell.command_list->args[0][0] == '/' \
				|| !ft_strncmp(g_shell.command_list->args[0], "./", 2) \
				|| !ft_strncmp(g_shell.command_list->args[0], "../", 3)))
	{
		pathes = get_pathes(g_shell.environment_list);
		if (pathes == NULL)
			return (0);
		ok = get_cmd(cmd->args, pathes);
		memclean(pathes, len_2d_str(pathes));
		if (!ok)
			return (0);
	}
	ret = file_check(cmd->args[0], 0);
	if (ret != 0)
	{
		g_shell.status = ret;
		ok = 0;
	}
	return (ok);
}
