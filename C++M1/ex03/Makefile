CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = output
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ 2> error.txt


fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJS)


re: fclean all

.PHONY: all clean fclean re
