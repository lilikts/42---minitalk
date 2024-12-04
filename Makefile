CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_SENDER = sender.c
SRCS_RECEIVER = receiver.c
OBJS_SENDER = $(SRCS_SENDER:.c=.o)
OBJS_RECEIVER = $(SRCS_RECEIVER:.c=.o)
NAME_SENDER = sender
NAME_RECEIVER = receiver

all: $(NAME_SENDER) $(NAME_RECEIVER)

$(NAME_SENDER): $(OBJS_SENDER)
	@$(CC) $(CFLAGS) -o $(NAME_SENDER) $(OBJS_SENDER)
$(NAME_RECEIVER): $(OBJS_RECEIVER)
	@$(CC) $(CFLAGS) -o $(NAME_RECEIVER) $(OBJS_RECEIVER)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SENDER) $(OBJS_RECEIVER)

fclean: clean
	rm -f $(NAME_SENDER) $(NAME_RECEIVER)

re: fclean all

.PHONY: all clean fclean re
