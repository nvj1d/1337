/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:22:17 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/04 20:13:03 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && n--)
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}

void	ft_exec(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(a, b);
	else if ((ft_strncmp(str, "ra\n", 3) == 0) || ft_strncmp(str, "rr\n", 3) == 0)
		ra(a);
	else if ((ft_strncmp(str, "rb\n", 3) == 0) || ft_strncmp(str, "rr\n", 3) == 0)
		rb(b);
	else if ((ft_strncmp(str, "sa\n", 3) == 0) || ft_strncmp(str, "ss\n", 3) == 0)
		sa(a);
	else if ((ft_strncmp(str, "sb\n", 3) == 0) || ft_strncmp(str, "ss\n", 3) == 0)
		sb(b);
	else if ((ft_strncmp(str, "rra\n", 4) == 0)
		|| ft_strncmp(str, "rrr\n", 4) == 0)
		rra(a);
	else if ((ft_strncmp(str, "rrb\n", 4) == 0)
		|| ft_strncmp(str, "rrr\n", 4) == 0)
		rrb(b);
	else
	{
		free_stack(a);
		free_stack(b);
		ft_error();
	}
}
