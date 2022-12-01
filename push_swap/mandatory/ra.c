/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:14:52 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:08:02 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if (*a == NULL)
		return ;
	while ((*a)->next)
	{
		*a = (*a)->next;
	}
	(*a)->next = tmp;
	tmp = tmp->next;
	*a = (*a)->next;
	(*a)->next = NULL;
	(*a) = tmp;
}
