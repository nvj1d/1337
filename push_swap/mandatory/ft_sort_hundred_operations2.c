/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred_operations2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:21:14 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:35:40 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_key_number(int *sorted_array, int size, int divided, int chunks)
{
	int	key_number;

	key_number = sorted_array[(size * divided) / chunks];
	return (key_number);
}

void	ft_move_to_top(t_stack **a, int index)
{
	int	divid;

	divid = ft_stack_size(*a) / 2;
	while (index != 0)
	{
		if (index <= divid)
		{
			ft_sort_hundred_ra_or_rra(a, "ra");
			index--;
		}
		else
		{
			ft_sort_hundred_ra_or_rra(a, "rra");
			index++;
			if (index == ft_stack_size(*a))
				break ;
		}
	}
}

int	ft_search_index(t_stack **a, int key)
{
	int	i;
	int	*arr;

	arr = stack_array(a);
	i = 0;
	while (i < ft_stack_size(*a))
	{
		if (arr[i] <= key)
			return (i);
		i++;
	}
	return (-1);
}
