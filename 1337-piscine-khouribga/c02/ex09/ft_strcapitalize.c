/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:22:01 by mnajid            #+#    #+#             */
/*   Updated: 2021/08/10 18:22:04 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_not_alpha(char *c)
{
	if ((*c >= 'a' && *c <= 'z')
		|| (*c >= 'A' && *c <= 'Z')
		|| (*c >= '0' && *c <= '9'))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int	ft_is_min(char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_minim(char *tr)
{
	int	i;

	i = 0;
	while (tr[i] != '\0')
	{
		if (tr[i] >= 'A' && tr[i] <= 'Z' )
		{
			tr[i] += 32;
		}
		i++;
	}
	return (tr);
}

char	*ft_strcapitalize(char *str)
{
	int	s;
	int	i;

	s = 0;
	i = 0;
	ft_minim(str);
	while (str[i] != '\0')
	{
		if (ft_is_min(&str[i]) && s == 0)
		{
			str[i] -= 32;
		}
		if (ft_is_not_alpha(&str[i]))
		{
			s = 0;
		}
		else
		{
			s = 1;
		}
		i++;
	}
	return (str);
}
