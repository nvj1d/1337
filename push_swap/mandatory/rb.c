/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:14:44 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:07:42 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	if (*b == NULL)
		return ;
	while ((*b)->next)
	{
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	tmp = tmp->next;
	*b = (*b)->next;
	(*b)->next = NULL;
	(*b) = tmp;
}
