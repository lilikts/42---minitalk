CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS_SENDER = server.c
SRCS_RECEIVER = client.c
OBJS_SENDER = $(SRCS_SENDER:.c=.o)
OBJS_RECEIVER = $(SRCS_RECEIVER:.c=.o)
NAME_SENDER = server
NAME_RECEIVER = client
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
all: $(NAME_SENDER) $(NAME_RECEIVER)

$(NAME_SENDER): $(LIBFT) $(OBJS_SENDER)
	@$(CC) $(CFLAGS) $(OBJS_SENDER) -L$(LIBFT_DIR) -lft -o $(NAME_SENDER)
$(NAME_RECEIVER):$(LIBFT) $(OBJS_RECEIVER)
	@$(CC) $(CFLAGS) $(OBJS_RECEIVER) -L$(LIBFT_DIR) -lft -o $(NAME_RECEIVER) 

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SENDER) $(OBJS_RECEIVER)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_SENDER) $(NAME_RECEIVER)
	$(MAKE) -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re
