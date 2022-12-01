/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:37:14 by mnajid            #+#    #+#             */
/*   Updated: 2021/12/08 18:06:05 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_to_eval(char c)
{
	int		i;
	char	*set;

	set = "cspdiuxX%";
	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_conversation(char c, va_list args, int *len)
{
	if (c == 'd' || c == 'i')
		*len += ft_putnbr_base10(va_arg(args, int));
	else if (c == 's')
		*len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		*len += ft_print_pointer(va_arg(args, void *));
	else if (c == 'c')
		*len += ft_putchar(va_arg(args, int));
	else if (c == 'u')
		*len += ft_putnbr_unsigned10(va_arg(args, unsigned int));
	else if (c == 'x')
		ft_putnbr_hex(va_arg(args, unsigned int), len);
	else if (c == 'X')
		ft_putnbr_hex_upper(va_arg(args, unsigned int), len);
	else if (c == '%')
		*len += ft_print_pourcentage();
	return (*len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_to_eval(str[i]))
				ft_conversation(str[i++], args, &len);
		}
		else
		{
			write(1, &str[i++], 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
