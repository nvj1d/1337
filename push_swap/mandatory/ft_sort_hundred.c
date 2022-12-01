/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:53:45 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:57:07 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_hundred(t_stack **a, t_stack **b)
{
	int	i;
	int	*sorted_array;
	int	key_number;
	int	size;

	size = ft_stack_size(*a);
	i = 1;
	sorted_array = ft_sort_array(a);
	while (i != 4)
	{
		key_number = ft_find_key_number(sorted_array, size, i, 4);
		ft_push_index(a, b, key_number);
		i++;
	}
	free(sorted_array);
	ft_sort_rest(a, b);
	while (ft_stack_size(*b) != 0)
	{
		ft_find_biggest_number(b);
		ft_sort_hundred_pa(a, b);
	}
}
