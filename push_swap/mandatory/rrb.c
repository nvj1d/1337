/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:41:06 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:58:00 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*hold_head;

	hold_head = *b;
	last = *b;
	tmp = *b;
	if (*b == NULL)
		return ;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next)
			last = last->next;
	}
	if (!tmp->next)
	{
		tmp->next = hold_head;
		last->next = NULL;
	}
	*b = tmp;
}
