/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:59:52 by mnajid            #+#    #+#             */
/*   Updated: 2021/08/15 19:41:27 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int     ft_isspace(char c)
{
        if (c == ' ' || c == '\t'
                || c == '\v' || c == '\r'
                || c == '\n' || c == '\f')
                return (1);
        return (0);
}

int	ft_is_base(char *pt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_len(pt) < 2)
		return (0);
	while (pt[i] != '\0')
	{
		j = i + 1;
		while (pt[j] != '\0')
		{
			if (pt[i] == pt[j])
				return (0);
			j++;
		}
		if (pt[i] == '+' || pt[i] == '-' || ft_isspace(pt[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_get_value(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	long long	i;
	long long	r;
	long long	c;

	c = 1;
	i = 0;
	r = 0;
	if (ft_is_base(base))
	{
		while (ft_isspace(str[i]))
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				c *= (-1);
			i++;
		}	
		while (ft_get_value(str[i], base) != -1)
		{
			r *= ft_len(base);
			r += ft_get_value(str[i], base);
			i++;
		}
	}
	return (r *= c);
}
