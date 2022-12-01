/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:35:14 by mnajid            #+#    #+#             */
/*   Updated: 2021/08/22 17:35:16 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
int	*ft_range(int min, int max)
{
	int	i;
	int	*ptr;

	i = 0;
	if (min < max)
	{
		ptr = (int *)malloc(sizeof(int) * (max - min));
		if (!ptr)
			return (NULL);
		while (min < max)
		{
			ptr[i] = min;
			min++;
			i++;
		}
		return (ptr);
	}
	return (NULL);
}
