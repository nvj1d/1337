/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:17:28 by mnajid            #+#    #+#             */
/*   Updated: 2022/07/23 20:49:05 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_head(void)
{
	static int	first_time = 1;
	char		*clear_screen;

	if (first_time)
	{
		clear_screen = "\e[1;1H\e[2J";
		write (1, clear_screen, 12);
		first_time = 0;
		printf("██╗   ███╗██╗███╗   ██╗██╗");
		printf("███████╗██╗  ██╗███████╗██╗     ██╗\n");
		printf("████╗ ████║██║████╗  ██║██║██╔════╝");
		printf("██║  ██║██╔════╝██║     ██║    \n");
		printf("██╔████╔██║██║██╔██╗ ██║██║██████");
		printf("█╗███████║█████╗  ██║     ██║  \n");
		printf("██║╚██╔╝██║██║██║╚██╗██║██║╚════██");
		printf("║██╔══██║██╔══╝  ██║     ██║  \n");
		printf("██║ ╚═╝ ██║██║██║ ╚████║██║███████║");
		printf("██║  ██║███████╗███████╗███████╗ \n");
		printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚");
		printf("═╝  ╚═╝╚══════╝╚══════╝╚══════╝ \n");
	}
}

static	char	*get_cmd(void)
{
	char	*str;

	str = readline("\033[0;32m Minishell\033[0;32m ~$ \033[4;0m");
	if (str && *str)
		add_history(str);
	return (str);
}

int	main(int ac, char **av, char **env)
{
	char	*cmd;

	(void)av;
	if (ac != 1)
	{
		print_error(av[1], "No such file or directory");
		return (127);
	}
	ft_head();
	ft_init(env);
	while (1)
	{
		signal_handler();
		cmd = get_cmd();
		parser(cmd);
		g_shell.command_list_head = g_shell.command_list;
		execution();
		clean_command_list(g_shell.command_list_head);
		g_shell.command_list_head = NULL;
	}
}
