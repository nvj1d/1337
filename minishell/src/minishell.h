/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:59:33 by mnajid            #+#    #+#             */
/*   Updated: 2022/07/23 20:53:56 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# define ENV_MODE 0
# define EXPORT_MODE 1

/* Struct Definition */
typedef struct s_redir
{
	int					type_redr;
	char				*filename;
	struct s_redir		*next;
}				t_redir;

typedef struct s_environment_list
{
	char				*key;
	char				*val;
	int					equal;
	struct s_environment_list	*next;
}				t_environment_list;

typedef struct s_cmd
{
	char			**args;
	int				pipe_in;
	int				pipe_out;
	t_redir			*redir_in;
	t_redir			*redir_out;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_minishell
{
	int				stdin;
	int				stdout;
	char			**env;
	int				status;
	int				env_changed;
	void			*temp;
	int				**fds;
	int				fd_write;
	int				fd_read;
	char			**functions_names;
	void			(*functions_array[7])(void);
	pid_t			*pids;
	t_environment_list		*environment_list;
	struct s_cmd	*command_list;
	struct s_cmd	*command_list_head;
}			t_minishell;

typedef enum e_stat
{
	default_pipe_in,
	default_pipe_out,
	pipe_in,
	pipe_out,
	redir_in_1,
	redir_in_2,
	redir_out_1,
	redir_out_2
}					t_stat;

/* Global Variable */
t_minishell	g_shell;

void		rl_replace_line(const char *text, int clear_undo);

/* Utils Directory */
void		print_error(char *arg, char *err_name);
void		exit_with_error(char *str);
int			file_check(char *file_path, int mode);
void		clear_all(t_minishell *shell);
int			len_2d_str(char **str);
void		clean_environment_list(t_environment_list *list);	
char		*collect_str_env(t_environment_list *elem);
void		clean_command_list(t_cmd *command_list);
void		cmd_end_works(int **fds, pid_t *pids, int i);

/* Parsing Directory */
void		*parser(char *str);
int			preparsing(const char *str);
char		*check_syntax(char *str, int i, int ok);
int			error_parser(char *cmd);
char		*get_cmds(char *str, int *i, int j);
char		*pipe_parse(int *i, char *str, int j, int k);
char		*get_redir(char *str, int *i, char ch);
void		ft_lstadd_back_parse(t_cmd **lst, t_cmd *new);
t_cmd		*ft_lstlast_parse(t_cmd *lst);
t_cmd		*ft_lstnew_parse(void *content);
void		ft_lstadd_back_redir(t_redir **lst, t_redir *new);
t_redir		*ft_lstnew_redir(void *content, int type);
t_redir		*ft_lstlast_redir(t_redir *lst);
void		redir(char **cmd, int i);
char		*ft_dollar(char *str, int *i, char **envp);

/* Builtins Directory */
void		set_functions_names(t_minishell *shell);
void		set_functions_array(t_minishell *shell);
void		pwd(void);
void		echo(void);
void		ft_exit(void);
int			parse_cmds(t_cmd *cmd);
void		memclean(char **s, size_t l);
char		*get_env(char *key, t_environment_list *environment_list);
char		*get_key(char *var);
void		env(void);
void		unset(void);
void		change_dir(void);
void		change_env_val(t_environment_list *elem, t_environment_list **environment_list);
void		del_lst_env_elem(t_environment_list *environment_list);
t_environment_list	*cp_env(t_environment_list *environment_list);
void		export(void);
void		print_environment_list(t_environment_list *environment_list, int flag);
int			valid_export(char *arg);

/* Main Directory */
void		ft_init(char **envp);
char		**collect_env(t_environment_list *environment_list);
t_environment_list	*get_env_elem(char *input);

/* Signal Directory */
void		signal_handler(void);
void		signal_init(void);
void		signal_init_here(void);

/* environment Directory */
void		lst_envadd_back(t_environment_list **list, t_environment_list *new);
t_environment_list	*lst_envlast(t_environment_list *lst);
int			check_atoi(char *str);
t_environment_list	*lst_envnew(char *key, char *val);

/* execution */
int			execution(void);
int			get_pids_fds(t_cmd *command_list);
void		close_fds(int **fds);
int			open_redirs(t_cmd *command_list);
int			here_doc(char *delimiter, int *fd);

#endif
