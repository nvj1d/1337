/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:43:17 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:30:19 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_sa(t_stack **a)
{
	sa(a);
	write(1, "sa\n", 3);
}

void	ft_sort_three_ra_sa(t_stack **a)
{
	ra(a);
	write(1, "ra\n", 3);
	sa(a);
	write(1, "sa\n", 3);
}

void	ft_sort_three_ra(t_stack **a)
{
	ra(a);
	write(1, "ra\n", 3);
}

void	ft_sort_three_rra(t_stack **a)
{
	rra(a);
	write(1, "rra\n", 4);
}

void	ft_sort_three_sa_ra(t_stack **a)
{
	sa(a);
	write(1, "sa\n", 3);
	ra(a);
	write(1, "ra\n", 3);
}
