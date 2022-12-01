# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 21:13:44 by mnajid            #+#    #+#              #
#    Updated: 2022/03/04 21:47:45 by mnajid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER_NA = checker

cc = gcc

flags = -Werror -Wall  -Wextra

#source files

srcs = mandatory/push_swap.c \
	mandatory/ft_parseint.c \
	mandatory/ft_sort_small.c \
	mandatory/ft_array_operations.c \
	mandatory/ft_sort_four_five_operations.c \
	mandatory/ft_stack_operations.c \
	mandatory/ft_sort_hundred.c \
	mandatory/ft_sort_three_operations.c \
	mandatory/ft_sort_ten_operations.c \
	mandatory/ft_sort_hundred_operations.c \
	mandatory/ft_sort_hundred_operations2.c \
	mandatory/ft_sort_five_hundred_operations.c \
	mandatory/ft_sort_five_hundred.c \
	mandatory/ft_sort_hundred_operations3.c \
	mandatory/ft_parseint_help.c \
	mandatory/pb.c \
	mandatory/ra.c \
	mandatory/rr.c \
	mandatory/rrb.c \
	mandatory/sa.c \
	mandatory/ss.c \
	mandatory/pa.c \
	mandatory/rb.c \
	mandatory/rra.c \
	mandatory/rrr.c \
	mandatory/sb.c 

#objets:

objets = $(srcs:%.c=%.o)

#bonus files:
bonus_srcs = bonus/checker.c \
	bonus/checker_help2.c \
	bonus/checker_help3.c \
	bonus/ft_parseint_help.c \
	bonus/pa.c \
	bonus/rb.c \
	bonus/rrb.c \
	bonus/sb.c \
	bonus/ft_array_operations.c \
	bonus/get_next_line.c \
	bonus/pb.c \
	bonus/rr.c \
	bonus/rrr.c \
	bonus/ss.c \
	bonus/checker_help.c \
	bonus/ft_parseint.c \
	bonus/get_next_line_utils.c \
	bonus/ra.c \
	bonus/rra.c \
	bonus/sa.c

#objets bonus:

bonus_obj = $(bonus_srcs:%.c=%.o)

#make push_swap

all : $(NAME)

$(NAME) : $(objets)
	@$(cc) $(objets) -o $@

#make the checker

bonus : $(CHECKER_NA)

$(CHECKER_NA) : $(bonus_obj)
	@$(cc) $(bonus_obj) -o $@

# mandatory obj

mandatory/%.o : mandatory/%.c
	@$(cc) $(flags) $< -c -o $@


# bonus obj

bonus/%.o : bonus/%.c
	@$(cc) $(flags) $< -c -o $@

#remove obj

clean :
	@rm -rf $(objets)
	@rm -rf $(bonus_obj)

#remove all

fclean: clean
	@rm -rf $(NAME) $(CHECKER_NA)

#exec all

re : fclean all bonus