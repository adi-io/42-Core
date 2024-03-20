CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_NAME = client
SERVER_NAME = server


all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS)
$(SERVER_NAME): $(SERVER_SRCS)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS)


fclean:
	rm -rf $(CLIENT_NAME) $(SERVER_NAME)


clean:
	rm -rf $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re

