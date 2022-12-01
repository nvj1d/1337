/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_help2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:28:26 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/04 21:05:52 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_not_int(t_stack **root)
{
	write(2, "Error\n", 6);
	free_stack(root);
	exit(1);
}

void	ft_fillstack(t_stack **a, char **av, int ac)
{
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		ft_check_rang(ft_parseint(av[i], a), a);
		push(a, ft_parseint(av[i], a));
		i--;
	}
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

int	ft_check_ordred(t_stack *a)
{
	while (a)
	{
		if (a->next)
		{
			if (a->value > a->next->value)
				return (0);
		}
		a = a->next;
	}
	return (1);
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
