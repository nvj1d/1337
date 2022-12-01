/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:51:03 by mnajid            #+#    #+#             */
/*   Updated: 2021/12/06 23:41:28 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned int nb, int *len)
{	
	char	*str;

	str = "0123456789abcdef";
	if (nb < 16)
	{
		write(1, &str[nb], 1);
		*len = *len + 1;
	}
	else
	{
		ft_putnbr_hex(nb / 16, len);
		ft_putnbr_hex(nb % 16, len);
	}
}
