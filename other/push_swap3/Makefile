NAME = push_swap
LIBFT = ./Libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
HEAD = ./Include/push_swap.h

SRCS = \
			oper_swap.c \
			oper_push.c \
			oper_rotate.c \
			oper_reverse.c \
			ps_main.c \
			utils.c \
			utils2.c \
			checks.c \
			atois.c \
			sort.c \
			maths.c

SRCS_DIR = Sources

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = Objects

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(FT_PRINTF) $(LIBFT) $(OBJS_DIR) $(OBJS)
#	$(CC) -g -fsanitize=address $(OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME)
# $(CC) $(CFLAGS) -g -fsanitize=address $(OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./Libft

$(FT_PRINTF):
	$(MAKE) -C ./ft_printf

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c 
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) clean -C ./Libft
	$(MAKE) clean -C ./ft_printf

fclean:clean
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)
	$(MAKE) fclean -C ./Libft
	$(MAKE) fclean -C ./ft_printf

re: fclean all

.PHONY: all bonus clean fclean re
