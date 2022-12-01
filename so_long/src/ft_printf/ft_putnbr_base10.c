/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base10.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:52:00 by mnajid            #+#    #+#             */
/*   Updated: 2021/12/05 19:52:05 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base10(int n)
{
	char	c;
	long	nb;
	int		len;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
		len++;
	}
	if (nb >= 0 && nb <= 9)
	{
		c = nb + '0';
		write(1, &c, 1);
		len++;
	}
	else
	{
		len += ft_putnbr_base10(nb / 10);
		len += ft_putnbr_base10(nb % 10);
	}
	return (len);
}
