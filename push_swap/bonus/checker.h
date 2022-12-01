/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:51:32 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/04 21:08:18 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

# define BUFFER_SIZE 1

//structure
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}t_stack;

void		exit_not_int(t_stack **root);
void		free_stack(t_stack **root);
t_stack		*new_node(int data);
void		push(t_stack **root, int data);
int			pop(t_stack **root);
int			ft_stack_size(t_stack *a);

void		ft_check_double(int val, t_stack **root);
void		ft_check_rang(long long n, t_stack **root);

long long	ft_parseint(const char *str, t_stack **a);
void		ft_check_numberv(const char *str, int d, t_stack **a);

void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

int			ft_stack_size(t_stack *a);

int			ft_check_ordred(t_stack *a);

//help
int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			ft_check_instructions(char *str);
void		ft_exec(t_stack **a, t_stack **b, char *str);
void		ft_error(void);

void		exit_not_int(t_stack **root);
void		ft_fillstack(t_stack **a, char **av, int ac);
void		free_stack(t_stack **root);

//next line
char		*get_next_line(int fd);

//help get next  line

char		*ft_strchr(char *src, int c);
size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);

int			ft_check_ordred(t_stack *a);
int			ft_stack_size(t_stack *a);

int			pop(t_stack **root);
void		push(t_stack **root, int data);

#endif