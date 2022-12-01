/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_envnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:16:41 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:16:42 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_environment_list	*lst_envnew(char *key, char *val)
{
	t_environment_list	*new_list;

	new_list = (t_environment_list *)malloc(sizeof(t_environment_list));
	if ((void *)0 == new_list)
		return ((void *)0);
	new_list->key = key;
	new_list->val = val;
	if (val)
		new_list->equal = 1;
	else
		new_list->equal = 0;
	new_list->next = (void *)0;
	return (new_list);
}
