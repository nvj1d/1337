# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 00:20:00 by mnajid            #+#    #+#              #
#    Updated: 2022/04/23 00:20:00 by mnajid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc 

SRC_FOLDER = ./src/

INCLUDES = ./src/so_long.h ./src/ft_printf/ft_printf.h ./src/get_next_line/get_next_line.h ./code/libft/libft.h 

SRC = so_long.c map.c map_check.c move.c draw.c
SRCS = $(addprefix $(SRC_FOLDER), $(SRC))
SRCOBJ = ${SRCS:.c=.o}

FT_PRINTF_FOLDER = ./src/ft_printf/
FT_PRINTF_FILES = ft_print_pointer.c ft_printf.c ft_putchar.c  ft_putnbr_hex.c  ft_putnbr_unsigned10.c \
		ft_print_pourcentage.c ft_putnbr_base10.c ft_putnbr_hex_upper.c  ft_putstr.c
SRCS_FT_PRINTF = $(addprefix $(FT_PRINTF_FOLDER), $(FT_PRINTF_FILES))

GET_NEXT_LINE_FOLDER = ./src/get_next_line/
GET_NEXT_LINE_FILES = get_next_line.c get_next_line_utils.c
SRCS_GET_NEXT_LINE = $(addprefix $(GET_NEXT_LINE_FOLDER), $(GET_NEXT_LINE_FILES))

LIBFT_FOLDER = ./src/libft/
LIBFT_FILES =	ft_atoi.c ft_isalpha.c ft_itoa.c ft_lstdelone.c ft_lstnew.c ft_memcpy.c ft_putendl_fd.c  ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c \
		ft_bzero.c ft_isascii.c ft_lstadd_back.c ft_lstiter.c ft_lstsize.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c \
		ft_calloc.c ft_isdigit.c ft_lstadd_front.c ft_lstlast.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c \
		ft_isalnum.c ft_isprint.c ft_lstclear.c ft_lstmap.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c
SRCS_LIBFT = $(addprefix $(LIBFT_FOLDER), $(LIBFT_FILES))

OTHER_SRCS = $(SRCS_FT_PRINTF) $(SRCS_GET_NEXT_LINE) $(SRCS_LIBFT)
OTHER_OBJ = ${OTHER_SRCS:.c=.o}

LIBS = ./src/ft_printf.a ./src/get_next_line.a ./src/libft.a

all : $(NAME)  

$(NAME) : ${SRCOBJ} $(OTHER_SRCS)
	@$(MAKE) -C $(FT_PRINTF_FOLDER)
	@echo "make ft_printf.a .." 
	@$(MAKE) -C $(GET_NEXT_LINE_FOLDER)
	@echo "make get_next_line.a .."
	@$(MAKE) -C $(LIBFT_FOLDER)
	@echo "make libft.a .."
	@$(CC) $(SRCOBJ) $(LIBS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "make so_long .. done!"

%.o : %.c ${INCLUDES}
	@$(CC) -Wall -Werror -Wextra -Imlx -c $< -o $@

clean :
	@rm -f $(LIBS) $(OTHER_OBJ) $(SRCOBJ)

fclean : clean
	@rm -f ${NAME} so_long

re : fclean all