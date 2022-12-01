/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:02:37 by mnajid            #+#    #+#             */
/*   Updated: 2021/08/10 18:24:41 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (*str == '\0')
	{
		return (1);
	}
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			i++;
		}
		else
		{
			return (0);
		}
		str++;
	}
	return (1);
}	
