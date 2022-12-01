/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:44:19 by mnajid            #+#    #+#             */
/*   Updated: 2021/12/05 19:45:25 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex_long(unsigned long nb)
{	
	int		j;
	char	*str;

	j = 0;
	str = "0123456789abcdef";
	if (nb < 16)
	{
		write(1, &str[nb], 1);
		j++;
	}
	else
	{
		j += ft_put_hex_long(nb / 16);
		j += ft_put_hex_long(nb % 16);
	}
	return (j);
}

int	ft_print_pointer(void *ptr)
{
	unsigned long	a;
	int				len;

	len = 0;
	a = (unsigned long)ptr;
	write(1, "0x", 2);
	len = ft_put_hex_long(a);
	len += 2;
	return (len);
}
