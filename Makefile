# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 22:06:44 by htekdemi          #+#    #+#              #
#    Updated: 2025/03/09 22:06:44 by htekdemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
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