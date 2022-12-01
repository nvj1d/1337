/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:32:30 by mnajid            #+#    #+#             */
/*   Updated: 2021/08/18 16:44:50 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	main(int ac, char **av)
{	
	int	i;
	int	j;

	i = 0;
	if (ac >= 2)
	{
		while (i < ac - 1)
		{
			j = 1;
			while (j < ac - i - 1)
			{
				if (ft_strcmp(av[j], av[j + 1]) > 0)
					ft_swap(&av[j], &av[j + 1]);
				j++;
			}
			i++;
		}
		i = 1;
		while (av[i])
		{
			ft_putstr(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
}
