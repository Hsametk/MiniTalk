CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a 
SRCS = ft_printf.c ft_words.c ft_numbers.c
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re