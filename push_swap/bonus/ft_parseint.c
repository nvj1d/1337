/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseInt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:06:53 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/04 21:01:43 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_rang(long long n, t_stack **root)
{
	if (n < -2147483648 || n > 2147483647)
		exit_not_int(root);
}

void	ft_check_double(int val, t_stack **root)
{
	int		count;
	t_stack	*head;

	count = 1;
	head = *root;
	while (head)
	{
		if (head->value == val)
			count++;
		head = head->next;
	}
	if (count >= 2)
		exit_not_int(root);
}

static int	ft_isspace(char c)
{
	if ((c == '\t') || (c == '\n')
		|| (c == '\v') || (c == '\f')
		|| (c == '\r') || (c == ' '))
		return (1);
	return (0);
}

void	ft_check_null(const char *str, int n, t_stack **a)
{
	if (str[n] == '\0')
		exit_not_int(a);
}

long long	ft_parseint(const char *str, t_stack **a)
{
	long long	i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	ft_check_null(str, 0, a);
	while (ft_isspace(str[i]))
		i++;
	ft_check_null(str, i, a);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	ft_check_numberv(&str[i], result * sign, a);
	return (result * sign);
}
