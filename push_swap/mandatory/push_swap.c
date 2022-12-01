/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:32:48 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/04 21:10:00 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_not_int(t_stack **root)
{
	write(2, "Error\n", 6);
	free_stack(root);
	exit(1);
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

// void ft_printAll(t_stack **root)
// {
// 	t_stack *tmp;
// 	printf("Elements:\n");
// 	if (*root == NULL)
// 		printf("the stack is empty!\n");
// 	tmp = *root;
// 	while (tmp != NULL)
// 	{
// 		printf("%d\n",tmp->value);
// 		tmp = tmp-> next;
// 	}
// }

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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	ft_fillstack(&a, av, ac);
	if (ft_check_ordred(a) == 1)
		return (0);
	else if (ac == 3)
		ft_sort_two(&a);
	else if (ac == 4)
		ft_sort_three(&a);
	else if (ac == 6 || ac == 5)
		ft_sort_four_five(&a, &b);
	else if (ac >= 7 && ac <= 11)
		ft_sort_ten(&a, &b);
	else if (ac > 11 && ac <= 101)
		ft_sort_hundred(&a, &b);
	else if (ac > 101)
		ft_sort_five_hundred(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
