/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned10.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:49:23 by mnajid            #+#    #+#             */
/*   Updated: 2021/12/06 23:43:27 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned10(unsigned int n)
{
	long	nb;
	char	c;
	int		len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
	}
	if (nb >= 0 && nb <= 9)
	{
		c = nb + '0';
		write(1, &c, 1);
		len++;
	}
	else
	{
		len += ft_putnbr_unsigned10(nb / 10);
		len += ft_putnbr_unsigned10(nb % 10);
	}
	return (len);
}
