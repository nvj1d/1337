/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:39:10 by mnajid            #+#    #+#             */
/*   Updated: 2021/11/13 15:08:45 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy( void *destination, const void *source, size_t size )
{
	size_t	i;
	char	*c_source;
	char	*c_destination;

	i = 0;
	if (!source && !destination)
		return (NULL);
	c_source = (char *)source;
	c_destination = (char *)destination;
	while (size--)
	{
		c_destination[i] = c_source[i];
		i++;
	}
	return (destination);
}
