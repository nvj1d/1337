/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:57:50 by mnajid            #+#    #+#             */
/*   Updated: 2021/11/05 20:58:06 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	s;
	size_t	i;

	j = 0;
	if (ft_strlen(dest) >= size)
	{
		return (size + ft_strlen(src));
	}
	else
	{
		j = ft_strlen(dest);
		i = ft_strlen(dest);
		s = 0;
		while (src[s] && j < size - 1)
		{
			dest[j] = src[s];
			s++;
			j++;
		}
		dest[j] = '\0';
		return (i + ft_strlen(src));
	}
}
