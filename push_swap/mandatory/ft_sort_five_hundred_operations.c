/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five_hundred_operations.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:37:45 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:39:28 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_sort_more_then_handred(t_stack **a, t_stack **b)
{
	if (ft_check_ordred(*a) == 1)
		return ;
	else if (ft_stack_size(*a) == 2)
		ft_sort_two(a);
	else if (ft_stack_size(*a) == 3)
		ft_sort_three(a);
	else if (ft_stack_size(*a) == 4 || ft_stack_size(*a) == 5)
		ft_sort_four_five(a, b);
	else if (ft_stack_size(*a) > 5 || ft_stack_size(*a) <= 10)
		ft_sort_rest_numbers(a, b);
	else if (ft_stack_size(*a) > 10)
		ft_sort_hundred(a, b);
}
