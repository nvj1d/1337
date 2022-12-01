/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:46:52 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:19:27 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	valid_export(char *arg)
{
	int	i;
	int	ok;

	i = -1;
	ok = 1;
	if (!ft_isalpha(arg[0]))
		ok = 0;
	while (arg[++i])
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '=')
			ok = 0;
	}
	if (!ok)
	{
		ft_putendl_fd("not a valid identifier", STDERR_FILENO);
		g_shell.status = 1;
	}
	return (ok);
}

static void	swap(t_environment_list *a, t_environment_list *b)
{
	char	*temp_key;
	char	*temp_val;
	int		temp_equal;

	temp_key = a->key;
	temp_val = a->val;
	temp_equal = a->equal;
	a->key = b->key;
	a->val = b->val;
	a->equal = b->equal;
	b->key = temp_key;
	b->val = temp_val;
	b->equal = temp_equal;
}

t_environment_list	*sort_environment_list(t_environment_list *start)
{
	int			swapped;
	t_environment_list	*ptr1;
	t_environment_list	*lptr;

	swapped = 1;
	lptr = NULL;
	if (start == NULL)
		return (NULL);
	while (swapped)
	{
		ptr1 = start;
		swapped = 0;
		while (ptr1->next != lptr)
		{
			if (ft_strcmp(ptr1->key, ptr1->next->key) > 0)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
	return (start);
}

t_environment_list	*cp_env(t_environment_list *environment_list)
{
	t_environment_list	*export;
	char		*key;
	char		*val;

	export = NULL;
	while (environment_list)
	{
		key = ft_strdup(environment_list->key);
		if (NULL == key)
			exit_with_error("minishell: -: malloc error");
		if (environment_list->val)
		{
			val = ft_strdup(environment_list->val);
			if (NULL == val)
				exit_with_error("minishell: -: malloc error");
		}
		else
			val = NULL;
		lst_envadd_back(&export, lst_envnew(key, val));
		environment_list = environment_list->next;
	}
	return (sort_environment_list(export));
}
