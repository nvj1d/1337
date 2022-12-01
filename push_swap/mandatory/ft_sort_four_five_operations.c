/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four_five_operations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:11:57 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:38:27 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_smallest_index(t_stack **a)
{
	int	*tab;
	int	n;
	int	i;
	int	min;
	int	index;

	tab = stack_array(a);
	n = ft_stack_size(*a);
	i = 0;
	min = tab[0];
	index = 0;
	while (i < n)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			index = i;
		}
		i++;
	}	
	free(tab);
	return (index);
}

void	ft_five_smallest_to_top(t_stack **a)
{
	int	index;

	index = ft_get_smallest_index(a);
	while (index != 0)
	{
		if (index <= 2)
			ft_sort_four_five_ra_or_rra(a, "ra");
		else
			ft_sort_four_five_ra_or_rra(a, "rra");
		index = ft_get_smallest_index(a);
	}
}

void	ft_sort_four_five_ra_or_rra(t_stack **a, char *str)
{
	if (*(++str) == 'a')
	{
		ra(a);
		write(1, "ra\n", 3);
	}
	else
	{
		rra(a);
		write(1, "rra\n", 4);
	}
}

int	ft_sort_four_five_pb(t_stack **a, t_stack **b)
{
	pb(a, b);
	write(1, "pb\n", 3);
	return (1);
}

void	ft_sort_four_five_pa(t_stack **a, t_stack **b)
{
	pa(a, b);
	write(1, "pa\n", 3);
}
