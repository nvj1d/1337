/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:06:51 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:07:15 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*hold_head;

	hold_head = *a;
	last = *a;
	tmp = *a;
	if (*a == NULL)
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
	*a = tmp;
}
