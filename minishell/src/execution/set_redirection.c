/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:51:50 by mnajid            #+#    #+#             */
/*   Updated: 2022/07/23 20:51:56 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	file_temp(t_redir *redir)
{
	int		status;
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		return (-1);
	pid = fork();
	signal_init();
	if (pid < 0)
	{
		close(fds[0]);
		close(fds[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (here_doc(redir->filename, fds) == -1)
			exit(1);
		exit(0);
	}
	waitpid(pid, &status, 0);
	close(fds[1]);
	if (status == -1)
		exit_with_error("minishell: -: malloc error");
	return (fds[0]);
}

int	set_redir_out(t_redir *redir)
{
	int		fd;

	fd = -2;
	while (redir)
	{
		if (fd != -2)
			close (fd);
		if (redir_out_1 == redir->type_redr)
			fd = open(redir->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (redir_out_2 == redir->type_redr)
			fd = open(redir->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			g_shell.status = 1;
			print_error(redir->filename, strerror(errno));
			return (0);
		}
		g_shell.fd_write = fd;
		redir = redir->next;
	}
	return (1);
}

int	set_redir_in(t_redir *redir)
{
	int		fd;

	fd = -2;
	while (redir)
	{
		if (redir_in_1 == redir->type_redr)
			fd = open(redir->filename, O_RDONLY);
		else if (redir_in_2 == redir->type_redr)
			fd = file_temp(redir);
		if (fd == -1)
		{
			g_shell.status = 1;
			print_error(redir->filename, strerror(errno));
			return (0);
		}
		g_shell.fd_read = dup(fd);
		close(fd);
		redir = redir->next;
	}
	return (1);
}

int	open_redirs(t_cmd *command_list)
{
	if (command_list->redir_in)
	{
		if (!set_redir_in(command_list->redir_in))
			return (0);
	}
	if (command_list->redir_out)
	{
		if (!set_redir_out(command_list->redir_out))
			return (0);
	}
	return (1);
}
