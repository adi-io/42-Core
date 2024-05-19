CC = cc
CFLAGS =
NAME = minishell
SRC = $(wildcard *.c)
LIBFT = ./libft/libft.a
OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -lreadline -o $@ 2> error.txt

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)  # Create obj directory if needed
	$(CC) $(CFLAGS) -c $< -o $@  # Compile and place object in OBJDIR

fclean: clean
	rm -rf $(NAME) error.txt

clean:
	rm -rf $(OBJDIR)

re: fclean all

# TEST RELATED MACROS:
run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re

