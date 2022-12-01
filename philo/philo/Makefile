# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 15:10:33 by mnajid            #+#    #+#              #
#    Updated: 2022/07/18 10:21:16 by mnajid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc 

flags = -Wall -Werror -Wextra

srcs = ./src/main.c \
		./src/free.c \
		./src/init.c \
		./src/utils.c \
		./src/utils2.c \
		./src/routine.c \
		./src/run.c \

		
objs = $(srcs:.c=.o)

HEADER = philo.h 

all : $(NAME)

$(NAME) : $(objs)
		$(CC) $(flags) $^ -o $@

%.o : %.c
		$(CC) $(flags) $< -c -o $@

clean : 
		rm -rf $(objs)

fclean : clean
		rm -rf $(NAME)

re :	fclean all