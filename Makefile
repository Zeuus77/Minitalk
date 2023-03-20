CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCSS =  server.c
SRCSC = client.c
SRCSSB = server_bonus.c
SRCSCB = client_bonus.c
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
NAME = client
NAME1 = server
UTILS = help.c
UTILSO = help.o

all: $(NAME) $(NAME1)


$(NAME) : $(UTILSO) $(SRCSC)
		$(CC) $(CFLAGS) $(UTILS) $(SRCSC)  -o $(NAME)
$(NAME1): $(UTILSO) $(SRCSS)
		$(CC) $(CFLAGS) $(UTILS) $(SRCSS) -o $(NAME1)
clean:
	rm -f *.o $(NAME) $(NAME1) $(CLIENT_BONUS) $(SERVER_BONUS)
fclean:
	rm -f *.o $(NAME) $(NAME1) $(CLIENT_BONUS) $(SERVER_BONUS)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(UTILSO) $(SRCSCB)
		$(CC) $(CFLAGS) $(UTILS) $(SRCSCB) -o $(CLIENT_BONUS)
$(SERVER_BONUS): $(UTILSO) $(SRCSSB)
		$(CC) $(CFLAGS) $(UTILS) $(SRCSSB) -o $(SERVER_BONUS)

re:	fclean all bonus

.PHONY: all clean fclean re
