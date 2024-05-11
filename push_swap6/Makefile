NAME = push_swap
BONUS_NAME = checker
LIBFT = ./Libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
HEAD = ../Include/push_swap.h

SRCS_1 = \
			ps_main.c \

SRCS_2 = \
			atois.c \
			checks_new.c \
			find_index.c \
			maths.c	\
			oper_swap.c \
			oper_push.c \
			oper_rotate.c \
			oper_reverse.c \
			new_sort.c \
			new_sort_utils.c \
			new_sort_utils2.c \
			sort.c \
			utils.c \
			utils2.c \

SRCS_DIR = Sources

OBJS_1 = $(SRCS_1:%.c=$(OBJS_DIR)/%.o)

OBJS_2 = $(SRCS_2:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = Objects

BONUS_SRCS = \
			checker.c \
			checker2.c \

BONUS_SRCS_DIR = Sources/Bonus

BONUS_OBJS = $(BONUS_SRCS:%.c=$(BONUS_OBJS_DIR)/%.o)

BONUS_OBJS_DIR = Objects/Bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

all: $(NAME)

$(NAME): $(FT_PRINTF) $(LIBFT) $(OBJS_DIR) $(OBJS_1) $(OBJS_2)
	$(CC) $(CFLAGS) $(OBJS_1) $(OBJS_2) $(FT_PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./Libft

$(FT_PRINTF):
	$(MAKE) -C ./ft_printf

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(FT_PRINTF) $(LIBFT) $(OBJS_DIR) $(OBJS_2) $(BONUS_OBJS_DIR) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJS_2) $(FT_PRINTF) $(LIBFT) -o $(BONUS_NAME)

$(BONUS_OBJS_DIR):
	mkdir -p $(BONUS_OBJS_DIR)

$(BONUS_OBJS_DIR)/%.o:$(BONUS_SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I $(HEAD)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) clean -C ./Libft
	$(MAKE) clean -C ./ft_printf

fclean:
	rm -f $(NAME) $(BONUS_NAME)
	rm -f ./a.out
	rm -f ./Sources/a.out
	rm -f ./push_swap
	rm -rf $(OBJS_DIR)
	$(MAKE) fclean -C ./Libft
	$(MAKE) fclean -C ./ft_printf

re: fclean all

.PHONY: all bonus clean fclean re
