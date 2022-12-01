/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:23:17 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:13:42 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_environment_list(int mode, t_environment_list *environment_list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (environment_list)
	{
		if (!environment_list->equal)
			j++;
		i++;
		environment_list = environment_list->next;
	}
	if (mode == 1)
		return (i);
	else
		return (i - j);
}

t_environment_list	*get_env_elem(char *input)
{
	t_environment_list	*elem;

	elem = (t_environment_list *)malloc(sizeof(t_environment_list));
	elem->equal = 0;
	if (elem == NULL)
		exit_with_error("error: in allocation!");
	elem->key = get_key(input);
	if (elem->key == NULL)
		exit_with_error("error: in allocation!");
	if (ft_strchr(input, '='))
	{
		elem->val = ft_strdup(ft_strchr(input, '=') + 1);
		if (elem->val == NULL)
			exit_with_error("error: in allocation!");
		elem->equal = 1;
	}
	else
		elem->val = NULL;
	elem->next = NULL;
	return (elem);
}

char	**collect_env(t_environment_list *environment_list)
{
	int		i;
	int		len;
	char	**env;

	i = 0;
	len = len_environment_list(0, g_shell.environment_list);
	env = (char **)malloc (sizeof(char *) * (len + 1));
	while (i < len)
	{
		if (environment_list->equal)
			env[i] = collect_str_env (environment_list);
		i++;
		environment_list = environment_list->next;
	}
	env[i] = NULL;
	return (env);
}

void	get_environment_list(t_environment_list **environment_list, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		lst_envadd_back(environment_list, get_env_elem(envp[i]));
	}
}

void	ft_init(char **env)
{
	g_shell.fd_read = -10;
	g_shell.fd_write = -10;
	g_shell.stdin = dup(STDIN_FILENO);
	g_shell.stdout = dup(STDOUT_FILENO);
	g_shell.status = 0;
	g_shell.environment_list = NULL;
	get_environment_list(&g_shell.environment_list, env);
	g_shell.env = collect_env(g_shell.environment_list);
	set_functions_array(&g_shell);
	set_functions_names(&g_shell);
}
