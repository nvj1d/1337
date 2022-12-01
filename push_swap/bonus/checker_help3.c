/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_help3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:55:15 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/03 17:57:26 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

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

t_stack	*new_node(int data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node -> value = data;
	node -> next = NULL;
	return (node);
}
