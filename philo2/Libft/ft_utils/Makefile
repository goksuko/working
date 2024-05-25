NAME = ft_utils.a
LIBFT = ../objects/*.o
FT_PRINTF_FD = ../ft_printf_fd/objects/*.o

SRCS = \
		ft_free_matrix.c \

SRCS_DIR = sources

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = objects

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
#$(NAME): $(OBJS_DIR) $(OBJS) $(LIBFT) $(FT_PRINTF_FD)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(LIBFT):
	$(MAKE) -C ../../Libft

$(FT_PRINTF_FD):
	$(MAKE) -C ../ft_printf_fd

clean:
	rm -rf $(OBJS_DIR)
#	$(MAKE) clean -C ../../Libft
#	$(MAKE) clean -C ../ft_printf_fd

fclean:clean
	rm -f $(NAME) ./a.out
#	$(MAKE) fclean -C ../../Libft
#	$(MAKE) fclean -C ../ft_printf_fd

re: fclean all

.PHONY: all clean fclean re