/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:46:17 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:21:01 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	preparsing(const char *str)
{
	char	ch;
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			ch = str[i];
			i++;
			while (str[i] && str[i] != ch)
				i++;
			if (!str[i] || str[i] != ch)
				return (0);
		}
		if (str[i] == '|')
		{
			while (str[++i] && str[i] == ' ')
				;
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
				return (0);
		}
	}
	return (1);
}

char	*check_syntax(char *str, int i, int ok)
{
	char	*temp;
	char	*temp_2;

	temp = ft_strdup(str);
	free(str);
	while (temp[++i])
	{
		if (temp[i] == '\"' && !ok)
		{
			i++;
			ok += 1;
		}
		if (temp[i] == '\"' && ok)
			ok--;
		if (temp[i] == '\'' && ok != 1)
			while (temp[++i] && temp[i] != '\'')
				;
		if (temp[i] == '$')
		{
			temp_2 = ft_strdup(temp);
			free(temp);
			temp = ft_dollar(temp_2, &(i), g_shell.env);
		}
	}
	return (temp);
}

int	error_parser(char *cmd)
{
	ft_putendl_fd(cmd, 2);
	return (-1);
}
