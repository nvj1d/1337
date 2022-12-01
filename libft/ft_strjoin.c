/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:40:02 by mnajid            #+#    #+#             */
/*   Updated: 2021/11/13 15:37:44 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*ptr;
	int		a;
	int		b;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	ptr = malloc(a + b + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)s1, a + 1);
	ft_strlcat(ptr, (char *)s2, a + b + 1);
	return (ptr);
}
