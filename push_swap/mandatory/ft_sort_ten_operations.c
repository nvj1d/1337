/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ten_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:37:33 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:31:12 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ten_smallest_to_top(t_stack **a)
{
	int	index;

	index = ft_get_smallest_index(a);
	while (index != 0)
	{
		if (index <= 5)
			ft_sort_ten_ra_or_rra(a, "ra");
		else
			ft_sort_ten_ra_or_rra(a, "rra");
		index = ft_get_smallest_index(a);
	}
}

void	ft_sort_ten_ra_or_rra(t_stack **a, char *str)
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

int	ft_sort_ten_pb(t_stack **a, t_stack **b)
{
	pb(a, b);
	write(1, "pb\n", 3);
	return (1);
}

void	ft_sort_ten_pa(t_stack **a, t_stack **b)
{
	pa(a, b);
	write(1, "pa\n", 3);
}
