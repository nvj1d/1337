/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 11:48:27 by mnajid            #+#    #+#             */
/*   Updated: 2021/08/15 11:49:50 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_is_base(char *tr)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	k = 0;
	if (ft_len(tr) < 2)
		return (0);
	while (tr[i])
	{
		j = i + 1;
		while (tr[j])
		{
			if (tr[i] == tr[j])
				return (0);
			j++;
		}
		if (tr[i] == '+' || tr[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;

	if (ft_is_base(base))
	{
		n = nbr;
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n < ft_len(base))
		{
			ft_putchar(base[n]);
		}
		else
		{
			ft_putnbr_base(n / ft_len(base), base);
			ft_putnbr_base(n % ft_len(base), base);
		}
	}
}
