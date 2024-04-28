NAME = MINISHELL
DEF_COLOR = \033[0;39m
CLR2 = \033[0;36m
CLR1 = \033[0;37m

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

# Directories
SRC_DIR =
OBJ_DIR = obj/
ERR_DIR = error_logs/
INCLUDE = include

# Sources
SRC_FILES = errors minishell_loop minishell parser redirections \
			tokenizer utils_lexer utils_redirections utils utils_two

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

LIBFT = libft.a

run:	$(NAME)
	@clear
	@echo
	@echo
	./$(NAME)

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)  # Create the directory if it doesn't exist
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

# Rule to build the executable
$(NAME): libft $(OBJ)
	mkdir -p $(ERR_DIR)
	$(CC) $(CFLAGS) -lreadline -o $@ $(OBJ) $(LIBFT) 2> $(ERR_DIR)/error.txt

# @clear
	@echo "$(CLR2)rdy$(DEF_COLOR)"
	@clear
	@echo "$(CLR2)rdy$(DEF_COLOR)"
all:	$(NAME)

libft:
		@ make -C libft/

norm:
		@clear
		norminette $(SRC)

clean:
		@ $(RM) $(OBJ)
		@ $(RM) $(OBJ)
		@ $(RM) $(NAME)
		@echo "$(CLR1)        $(NAME) wiped! have a nice day ;-)$(DEF_COLOR)"
		@echo "$(CLR2)        please recompile to proceed.$(DEF_COLOR)"
		@sleep 1

fclean: clean
		@ $(RM) $(NAME)
		@ $(RM) $(NAME)
		@ $(RM) libft.a
		@ make -C libft/ clean
		@clear
		@echo "$(CLR1)        all wiped boss! have a nice day ;-)$(DEF_COLOR)"
		@sleep 1
		@clear

re: fclean all $(NAME)
	@sleep 1

.PHONY: all libft clean fclean re norm run


VALGRIND = valgrind --leak-check=full --show-leak-kinds=all -s

