/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:29:26 by mnajid            #+#    #+#             */
/*   Updated: 2021/11/09 17:36:23 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"libft.h"

static int	ft_isspace(char c)
{
	if ((c == '\t') || (c == '\n')
		|| (c == '\v') || (c == '\f')
		|| (c == '\r') || (c == ' '))
		return (1);
	return (0);
}

int	ft_atoi(const	char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}
