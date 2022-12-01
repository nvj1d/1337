/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:47:04 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:19:42 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd(void)
{
	char	*pwd;
	char	buf[4096];

	pwd = getcwd(buf, sizeof(buf));
	if (pwd)
	{
		ft_putendl_fd(buf, STDOUT_FILENO);
		g_shell.status = 0;
	}
	else
	{
		perror("minishell: pwd: ");
		g_shell.status = 127;
	}
}
