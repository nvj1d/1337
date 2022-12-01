/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:49:43 by mnajid            #+#    #+#             */
/*   Updated: 2021/12/06 23:42:15 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex_upper(unsigned int n, int *len)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (n < 16)
	{
		write(1, &str[n], 1);
		*len += 1;
	}
	else
	{
		ft_putnbr_hex_upper(n / 16, len);
		ft_putnbr_hex_upper(n % 16, len);
	}
}
