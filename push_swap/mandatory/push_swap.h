/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:31:55 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/04 20:44:50 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

//structure
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}t_stack;

//stack operations
void		exit_not_int(t_stack **root);
void		free_stack(t_stack **root);
t_stack		*new_node(int data);
void		push(t_stack **root, int data);
int			pop(t_stack **root);
int			ft_stack_size(t_stack *a);
void		ft_printAll(t_stack **root);

//check
void		ft_check_double(int val, t_stack **root);
void		ft_check_rang(long long n, t_stack **root);

//check Int and print
long long	ft_parseint(const char *str, t_stack **a);
void		ft_check_numberv(const char *str, int d, t_stack **a);
void		ft_printAll(t_stack **root);

//push_swap operations
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

//get the size of stack
int			ft_stack_size(t_stack *a);

//check if ordred
int			ft_check_ordred(t_stack *a);

//two
void		ft_sort_two(t_stack **a);

//three
void		ft_sort_three(t_stack **a);

void		ft_sort_three_sa(t_stack **a);
void		ft_sort_three_ra_sa(t_stack **a);
void		ft_sort_three_ra(t_stack **a);
void		ft_sort_three_rra(t_stack **a);
void		ft_sort_three_sa_ra(t_stack **a);

//five
void		ft_sort_four_five(t_stack **a, t_stack **b);

void		ft_five_smallest_to_top(t_stack **a);
int			ft_get_smallest_index(t_stack **a); //works for all

void		ft_sort_four_five_ra_or_rra(t_stack **a, char *str);
void		ft_sort_four_five_pa(t_stack **a, t_stack **b);
int			ft_sort_four_five_pb(t_stack **a, t_stack **b);

//ten
void		ft_sort_ten(t_stack **a, t_stack **b);

void		ft_ten_smallest_to_top(t_stack **a);
void		ft_sort_ten_ra_or_rra(t_stack **a, char *str);
int			ft_sort_ten_pb(t_stack **a, t_stack **b);
void		ft_sort_ten_pa(t_stack **a, t_stack **b);

//hundred
void		ft_sort_hundred(t_stack **a, t_stack **b);

int			ft_search_index(t_stack **a, int key);
void		ft_move_to_top(t_stack **a, int index);
int			ft_find_key_number(int *r, int c, int d, int e);
int			ft_get_biggest_index(t_stack **b);
void		ft_find_biggest_number(t_stack **b);
void		ft_push_index(t_stack **a, t_stack **b, int key);
void		ft_sort_rest(t_stack **a, t_stack **b);
void		ft_sort_rest_numbers(t_stack **a, t_stack **b);

//five hundred
void		ft_sort_five_hundred(t_stack **a, t_stack **b);

void		ft_sort_more_then_handred(t_stack **a, t_stack **b);
void		ft_sort_hundred_rb_or_rrb(t_stack **b, char *str);
void		ft_sort_hundred_ra_or_rra(t_stack **a, char *str);
void		ft_sort_hundred_pb(t_stack **a, t_stack **b);
void		ft_sort_hundred_pa(t_stack **a, t_stack **b);

//array operations
int			*stack_array(t_stack **a);
int			*ft_sort_array(t_stack **a);

#endif