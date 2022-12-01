/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:56:55 by mnajid            #+#    #+#             */
/*   Updated: 2022/07/23 20:57:29 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	here_doc(char *delimiter, int *fd)
{
	char	*str;

	signal_init_here();
	while (1)
	{
		str = readline("heredoc> ");
		if (!ft_strcmp(str, delimiter))
			break ;
		ft_putendl_fd(str, fd[1]);
		free(str);
	}
	close(fd[0]);
	close(fd[1]);
	return (1);
}
