#MAKEFILEPRINTF

NAME = libftprintf.a
CC =	cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c  ft_wordsandcharachter.c  ft_numberandhixadicimal.c 
		   

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)  

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
