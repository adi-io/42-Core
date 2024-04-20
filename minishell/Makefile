NAME = MINISHELL

CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)
LIBFT = ./libft/libft.a
OBJS = $(SRC:.c=.o)

RM = rm -rf
CC = cc


all: $(NAME)

$(NAME): $(SRC:.c=.o) $(LIBFT)
	$(CC) $(CFLAGS) $^  -lreadline -o $@ 2> error.txt


fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJS)


re: fclean all

.PHONY: all clean fclean re
