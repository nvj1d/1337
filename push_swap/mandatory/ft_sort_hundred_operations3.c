/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred_operations3.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:34:07 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:34:30 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_hundred_ra_or_rra(t_stack **a, char *str)
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

void	ft_sort_hundred_rb_or_rrb(t_stack **b, char *str)
{
	if (*(++str) == 'b')
	{
		rb(b);
		write(1, "rb\n", 3);
	}
	else
	{
		rra(b);
		write(1, "rrb\n", 4);
	}
}

void	ft_sort_hundred_pb(t_stack **a, t_stack **b)
{
	pb(a, b);
	write(1, "pb\n", 3);
}

void	ft_sort_hundred_pa(t_stack **a, t_stack **b)
{
	pa(a, b);
	write(1, "pa\n", 3);
}
