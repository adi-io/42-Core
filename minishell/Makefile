CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = MINISHELL
SRC = $(wildcard *.c)
LIBFT = ./libft/libft.a
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC:.c=.o) $(LIBFT)
	$(CC) $(CFLAGS) $^  -lreadline -o $@ 2> error.txt


fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJS)


re: fclean all

.PHONY: all clean fclean re
