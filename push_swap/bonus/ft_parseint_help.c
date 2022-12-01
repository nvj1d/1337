/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseInt_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:31:23 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/04 21:08:31 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

void	ft_check_numberv(const char *str, int d, t_stack **a)
{
	if (*str != '\0' && !(*str >= '0' && *str <= '9'))
		exit_not_int(a);
	ft_check_double(d, a);
}

void	ft_check_number(char *str, t_stack **root)
{
	int	i;

	i = 0;
	if (str[i] != '\0' && str[i] < '0' && str[i] > '9')
		exit_not_int(root);
}
