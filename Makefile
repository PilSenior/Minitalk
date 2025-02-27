NAME = minitalk
SERVER = SERVER
CLIENT = client
CC =    cc
CFLAGS = -Wall -Wextra -Werror
RM  = rm -f

all : $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): server.c
	$(CC) $(CFLAGS) -o server server.c

$(CLIENT): client.c
	$(CC) $(CFLAGS) -o client client.c

clean:
	$(RM) $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all $(NAME) clean fclean re