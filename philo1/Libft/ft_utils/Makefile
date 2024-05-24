NAME = ft_utils.a

#SRCS = $(shell find ./sources -iname "*.c")
SRCS = \
		ft_free_matrix.c \

SRCS_DIR = sources

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = objects

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJS_DIR)

fclean:clean
	rm -f $(NAME) ./a.out

re: fclean all

.PHONY: all clean fclean re