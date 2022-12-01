/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:01:47 by mnajid            #+#    #+#             */
/*   Updated: 2021/11/13 14:43:04 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;
	t_list	*temp;

	temp = *lst;
	if (del)
	{
		while (temp)
		{
			nxt = temp->next;
			del(temp->content);
			free(temp);
			temp = nxt;
		}
		*lst = NULL;
	}
}
