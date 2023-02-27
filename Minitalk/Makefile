CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = client.c server.c ft_atoi.c
CLIENT = client
SERVER = server
NAME = placeholder

all: $(CLIENT) $(SERVER)  

$(NAME): all

clean:
	rm -f *.o $(CLIENT) $(SERVER)
fclean:
	rm -f *.o $(CLIENT) $(SERVER)

re:	fclean all	

.PHONY: $(NAME)