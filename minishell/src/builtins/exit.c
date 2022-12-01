/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:46:49 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:19:23 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

unsigned long long	ft_atoi_ull(const char *str)
{
	int					i;
	int					check_neg;
	unsigned long long	res;

	i = 0;
	res = 0;
	check_neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			check_neg = -1;
	}
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		if (res > __LONG_MAX__ && res - __LONG_MAX__ > 1 && check_neg == 2)
			return (0);
		if (res > __LONG_MAX__ && check_neg == 1)
			return (1);
		i++;
	}
	return (res * check_neg);
}

int	check_atoi(char *str)
{
	int					i;
	unsigned long long	res;

	i = 0;
	while (str[i])
	{
		if (('-' == str[i] || '+' == str[i]) && i != 0)
			return (0);
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	res = ft_atoi_ull(str);
	if ((2 < ft_strlen(str)) && (1 == res || 0 == res))
		return (0);
	return (1);
}

void	ft_exit(void)
{
	char	**args;

	args = g_shell.command_list->args;
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (len_2d_str(args) > 2 && check_atoi(args[1]))
	{
		print_error("exit", "too many arguments");
		g_shell.status = 1;
		return ;
	}
	if (args[1])
	{
		if (check_atoi(args[1]))
			g_shell.status = ft_atoi_ull(args[1]);
		else
		{
			print_error("exit", "numeric argement required");
			g_shell.status = 255;
		}
	}
	clear_all(&g_shell);
	exit (g_shell.status);
}
