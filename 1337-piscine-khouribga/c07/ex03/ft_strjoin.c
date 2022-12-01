/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:05:50 by mnajid            #+#    #+#             */
/*   Updated: 2021/08/23 10:06:03 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		*dest = src[i];
		i++;
		dest++;
	}
	return (dest);
}

int	sum_lenth(int size, char **strs, int size_of_sep)
{
	int	i;
	int	len;

	i = 0;
	len = -1 * size_of_sep;
	while (i < size)
	{
		len += ft_strlen(strs[i]) + size_of_sep;
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*tab;

	i = 0;
	if (size == 0)
	{
		tab = (char *)malloc(sizeof(char));
		return (tab);
	}
	len = sum_lenth(size, strs, ft_strlen(sep));
	tab = (char *)malloc((len + 1) * sizeof(char));
	if (tab == NULL)
		return (0);
	while (i < size)
	{
		tab = ft_strcpy(tab, strs[i]);
		if (i < size - 1)
			tab = ft_strcpy(tab, sep);
		i++;
	}
	*tab = '\0';
	return (tab - len);
}
