NAME = libftprintf.a

srcs = ft_print_pointer.c ft_printf.c ft_putchar.c ft_putnbr_hex.c \
	ft_putnbr_unsigned10.c ft_print_pourcentage.c ft_putnbr_base10.c \
	ft_putnbr_hex_upper.c ft_putstr.c

objets = $(srcs:.c=.o)

all : $(NAME)

$(NAME) : $(objets) ft_printf.h
	ar rcs $@ $^

%.o : %.c
	gcc -Wall -Werror -Wextra -c $< -o $@

clean :
	rm -f $(objets)

fclean : clean
	rm -f $(NAME)

re : fclean all
	