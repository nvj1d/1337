/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:22:04 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/02 20:52:49 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_array(t_stack **a)
{
	int		*tab;
	t_stack	*tmp;
	int		size;
	int		n;
	int		i;

	i = 0;
	n = ft_stack_size(*a);
	tmp = *a;
	size = ft_stack_size(*a);
	tab = (int *)malloc(sizeof(int) * (size + 1));
	while (i < n)
	{
		tab[i++] = tmp->value;
		tmp = tmp->next;
	}
	return (tab);
}

void	swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	*ft_sort_array(t_stack **a)
{
	int	*arr;
	int	n;
	int	i;
	int	j;
	int	min_idx;

	n = ft_stack_size(*a);
	arr = stack_array(a);
	i = 0;
	while (i < n - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		swap(&arr[min_idx], &arr[i]);
		i++;
	}
	return (arr);
}
