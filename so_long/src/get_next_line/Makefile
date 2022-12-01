# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 20:28:37 by mnajid            #+#    #+#              #
#    Updated: 2022/04/22 21:02:26 by mnajid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

srcs = get_next_line.c get_next_line_utils.c

objets = $(srcs:.c=.o)

all : $(NAME)

$(NAME) : $(objets)
	@ar rcs $@ $^
	@mv $(NAME) ..

%.o : %.c
	@gcc -Wall -Werror -Wextra -c $< -o $@

clean :
	@rm -f $(objets)

fclean : clean
	@rm -f $(NAME)

re : fclean all
	