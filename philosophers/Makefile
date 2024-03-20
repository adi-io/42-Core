CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
NAME = philo


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^


fclean: clean
	rm -rf $(NAME)


clean:
	rm -rf $(OBJS)

re: fclean all

.PHONY: all clean fclean re
