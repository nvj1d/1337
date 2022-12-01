/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred_operations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:18:24 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:37:26 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_biggest_index(t_stack **b)
{
	int	i;
	int	*tab;
	int	max;
	int	index;
	int	n;

	i = 0;
	tab = stack_array(b);
	n = ft_stack_size(*b);
	index = 0;
	max = tab[0];
	while (i < n)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			index = i;
		}
		i++;
	}
	free(tab);
	return (index);
}

void	ft_find_biggest_number(t_stack **b)
{
	int	index;

	index = ft_get_biggest_index(b);
	while (index != 0)
	{
		if (index <= ft_stack_size(*b) / 2)
			ft_sort_hundred_rb_or_rrb(b, "rb");
		else
			ft_sort_hundred_rb_or_rrb(b, "rrb");
		index = ft_get_biggest_index(b);
	}
}

void	ft_push_index(t_stack **a, t_stack **b, int key)
{
	int	index;

	index = ft_search_index(a, key);
	while (index != -1)
	{
		ft_move_to_top(a, index);
		ft_sort_hundred_pb(a, b);
		index = ft_search_index(a, key);
	}
}

void	ft_sort_rest(t_stack **a, t_stack **b)
{
	if (ft_stack_size(*a) == 2)
	{
		if (!ft_check_ordred(*a))
		{
			sa(a);
			write(1, "sa\n", 3);
		}
	}
	else if (ft_stack_size(*a) == 3)
		ft_sort_three(a);
	else if (ft_stack_size(*a) == 4 || ft_stack_size(*a) == 5)
		ft_sort_four_five(a, b);
	else if (ft_stack_size(*a) > 5)
		ft_sort_rest_numbers(a, b);
}

void	ft_sort_rest_numbers(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stack_size(*a);
	if (ft_check_ordred(*a) == 1)
		return ;
	while (ft_stack_size(*a) > 5)
	{
		ft_ten_smallest_to_top(a);
		ft_sort_hundred_pb(a, b);
	}
	ft_sort_four_five(a, b);
	while (ft_stack_size(*a) != size)
		ft_sort_hundred_pa(a, b);
}
