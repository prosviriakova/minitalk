SERVER = server
CLIENT = client

SRCS_SERVER = src/server.c
SRCS_CLIENT = src/client.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

INCLUDE = include

LIBFT = libft/libft.a
LIBFT_PATH = libft/
LIBFT_INCLUDE = libft/include

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(CLIENT) $(SERVER)

$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -L$(LIBFT_PATH) -lft -o $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -L$(LIBFT_PATH) -lft -o $(SERVER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFT_INCLUDE) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
