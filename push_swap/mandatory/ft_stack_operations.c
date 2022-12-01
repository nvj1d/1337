/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:38:28 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:57:38 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node -> value = data;
	node -> next = NULL;
	return (node);
}

void	push(t_stack **root, int data)
{
	t_stack	*node;

	node = new_node(data);
	node->next = *root;
	*root = node;
}

int	pop(t_stack **root)
{
	t_stack	*temp;
	int		popped;

	temp = *root;
	*root = (*root)->next;
	popped = temp->value;
	free(temp);
	return (popped);
}

int	ft_stack_size(t_stack *a)
{
	int		k;
	t_stack	*tmp;

	tmp = a;
	k = 0;
	if (tmp == NULL)
		return (0);
	while (tmp)
	{
		k++;
		tmp = tmp ->next;
	}
	return (k);
}

void	free_stack(t_stack **root)
{
	t_stack	*tmp;

	while (*root)
	{
		tmp = *root;
		tmp->value = 0;
		*root = (*root)->next;
		free(tmp);
	}		
}
