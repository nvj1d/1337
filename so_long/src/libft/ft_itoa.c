/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:57:27 by mnajid            #+#    #+#             */
/*   Updated: 2021/11/13 14:40:28 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static size_t	dig_nb(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_filltab(char *ptr, long nb, size_t len, size_t i)
{
	ptr[len + i] = '\0';
	if (nb < 0)
	{	
		ptr[0] = '-';
		nb *= -1;
	}
	while (len)
	{
		ptr[len + i - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*ptr;
	size_t	num;
	size_t	i;

	i = 0;
	nb = n;
	num = dig_nb(nb);
	if (nb < 0)
		i++;
	ptr = malloc(num + i + 1);
	if (!ptr)
		return (NULL);
	ptr = ft_filltab(ptr, nb, num, i);
	return (ptr);
}
