/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:23:13 by mnajid            #+#    #+#             */
/*   Updated: 2021/11/05 20:23:49 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isprint(int ch)
{
	if (ch >= 32 && ch < 127)
		return (1);
	return (0);
}