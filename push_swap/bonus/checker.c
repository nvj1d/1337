/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:49:48 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/03 14:49:48 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checksorted(t_stack **a, t_stack **b)
{
	if (ft_check_ordred(*a) == 1 && *b == NULL)
	{
		write(1, "OK\n", 3);
		free_stack(a);
		free_stack(b);
	}
	else
	{
		write(1, "KO\n", 3);
		free_stack(a);
		free_stack(b);
	}
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	b = NULL;
	if (ac < 2)
		return (0);
	ft_fillstack(&a, av, ac);
	if (!a)
		ft_error();
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		ft_exec(&a, &b, str);
		free(str);
	}
	ft_checksorted(&a, &b);
	return (0);
}
