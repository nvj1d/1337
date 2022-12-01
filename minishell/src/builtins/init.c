/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:46:58 by mnajid            #+#    #+#             */
/*   Updated: 2022/06/19 17:19:34 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_functions_names(t_minishell *shell)
{
	char	*all_builtins;

	all_builtins = ft_strdup("cd env echo exit export pwd unset");
	if (all_builtins == NULL)
		exit_with_error("minishell: malloc error");
	shell->functions_names = ft_split(all_builtins, ' ');
	free(all_builtins);
	if (shell->functions_names == NULL)
		exit_with_error("minishell: malloc error");
}

void	set_functions_array(t_minishell *shell)
{
	shell->functions_array[0] = change_dir;
	shell->functions_array[1] = env;
	shell->functions_array[2] = echo;
	shell->functions_array[3] = ft_exit;
	shell->functions_array[4] = export;
	shell->functions_array[5] = pwd;
	shell->functions_array[6] = unset;
}
