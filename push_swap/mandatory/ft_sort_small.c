/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:08:32 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:32:03 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **a)
{
	sa(a);
	write(1, "sa\n", 3);
}

void	ft_sort_three(t_stack **a)
{
	int	i;
	int	j;
	int	k;

	i = (*a)->value;
	j = (*a)->next->value;
	k = (*a)->next->next->value;
	if (i > j && j < k && k > i)
		ft_sort_three_sa(a);
	else if (i > j && j > k && k < i)
		ft_sort_three_ra_sa(a);
	else if (i > j && j < k && k < i)
		ft_sort_three_ra(a);
	else if (i < j && j > k && k < i)
		ft_sort_three_rra(a);
	else if (i < j && j > k && k > i)
		ft_sort_three_sa_ra(a);
}

void	ft_sort_four_five(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (ft_stack_size(*a) == 5)
	{
		ft_five_smallest_to_top(a);
		i += ft_sort_four_five_pb(a, b);
	}
	if (ft_stack_size(*a) == 4)
	{
		ft_five_smallest_to_top(a);
		i += ft_sort_four_five_pb(a, b);
	}
	ft_sort_three(a);
	while (i--)
		ft_sort_four_five_pa(a, b);
}

void	ft_sort_ten(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (ft_stack_size(*a) != 5)
	{
		ft_ten_smallest_to_top(a);
		i += ft_sort_ten_pb(a, b);
	}
	ft_sort_four_five(a, b);
	while (i--)
		ft_sort_ten_pa(a, b);
}
