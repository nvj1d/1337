/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:25:53 by mnajid            #+#    #+#             */
/*   Updated: 2021/08/12 17:36:01 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	s;
	unsigned int	i;

	j = 0;
	if (len(dest) >= size)
	{
		return (size + len(src));
	}
	else
	{
		j = len(dest);
		i = len(dest);
		s = 0;
		while (src[s] && j < size - 1)
		{
			dest[j] = src[s];
			s++;
			j++;
		}
		dest[j] = '\0';
		return (i + len(src));
	}
}
