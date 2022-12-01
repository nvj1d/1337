/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_envadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:16:25 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:16:28 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	lst_envadd_back(t_environment_list **list, t_environment_list *new)
{
	t_environment_list	*tmp;

	if (list)
	{
		if (*list)
		{
			tmp = lst_envlast(*list);
			tmp->next = new;
		}
		else
		{
			*list = new;
		}
	}
}
