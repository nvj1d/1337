/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:41:17 by mnajid            #+#    #+#             */
/*   Updated: 2021/08/17 17:05:37 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while ((i * i) <= nb)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb >= 0)
	{
		while (ft_is_prime(nb) == 0)
			nb++;
		return (nb);
	}
	return (2);
}
