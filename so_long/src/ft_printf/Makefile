# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 20:25:19 by mnajid            #+#    #+#              #
#    Updated: 2022/04/23 00:22:19 by mnajid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

srcs = ft_print_pointer.c ft_printf.c ft_putchar.c ft_putnbr_hex.c \
	ft_putnbr_unsigned10.c ft_print_pourcentage.c ft_putnbr_base10.c \
	ft_putnbr_hex_upper.c ft_putstr.c

objets = $(srcs:.c=.o)

all : $(NAME)

$(NAME) : $(objets) ft_printf.h
	@ar rcs $@ $^
	@mv $(NAME) ..

%.o : %.c
	@gcc -Wall -Werror -Wextra -c $< -o $@

clean :
	@rm -f $(objets)

fclean : clean
	@rm -f $(NAME)

re : fclean all
	