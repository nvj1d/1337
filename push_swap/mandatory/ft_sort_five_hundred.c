/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five_hundred.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:37:18 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:39:00 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five_hundred(t_stack **a, t_stack **b)
{
	int	i;
	int	key_number;
	int	*sorted_array;
	int	size;

	size = ft_stack_size(*a);
	i = 1;
	sorted_array = ft_sort_array(a);
	while (i != 8)
	{
		key_number = ft_find_key_number(sorted_array, size, i, 8);
		ft_push_index(a, b, key_number);
		i++;
	}
	free(sorted_array);
	ft_sort_more_then_handred(a, b);
	while (ft_stack_size(*b) != 0)
	{
		ft_find_biggest_number(b);
		ft_sort_hundred_pa(a, b);
	}
}
