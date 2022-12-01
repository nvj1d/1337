/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:49:24 by mnajid            #+#    #+#             */
/*   Updated: 2021/12/13 21:15:38 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_print_pourcentage(void);

int		ft_putnbr_base10(int n);
void	ft_putnbr_hex(unsigned int nb, int *len);
int		ft_putnbr_unsigned10(unsigned int n);
int		ft_print_pointer(void *ptr);
void	ft_putnbr_hex_upper(unsigned int i, int *len);

#endif
