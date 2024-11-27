CC = c++
CFLAGS = -Wall -Wextra -Werror
NAME = output
SRC = AForms.cpp Bureaucrat.cpp  main.cpp  PresidentialPardonForm.cpp  RobotomyRequestForm.cpp  ShrubberyCreationForm.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJS)


re: fclean all

.PHONY: all clean fclean re
