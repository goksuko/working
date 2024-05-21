NAME = pipex
BONUS_NAME = pipex_bonus
LIBFT = ./Libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a

SRCS_1 = \
			pipex_main.c \

SRCS_2 = \
			utils.c \
			ft_putstr2_fd.c \
			path.c \

SRCS_DIR = Sources
OBJS_1 = $(SRCS_1:%.c=$(OBJS_DIR)/%.o)
OBJS_2 = $(SRCS_2:%.c=$(OBJS_DIR)/%.o)
OBJS_DIR = Objects

BONUS_SRCS_1 = \
			pipex_main_bonus.c

BONUS_SRCS_2 = \
			utils_bonus.c \
			ft_putstr2_fd_bonus.c \
			path_bonus.c \

BONUS_SRCS_DIR = Sources/Bonus
BONUS_OBJS_1 = $(BONUS_SRCS_1:%.c=$(BONUS_OBJS_DIR)/%.o)
BONUS_OBJS_2 = $(BONUS_SRCS_2:%.c=$(BONUS_OBJS_DIR)/%.o)
BONUS_OBJS_DIR = Objects/Bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(FT_PRINTF) $(LIBFT) $(OBJS_DIR) $(OBJS_1) $(OBJS_2)
	$(CC) $(OBJS_1) $(OBJS_2) $(FT_PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./Libft

$(FT_PRINTF):
	$(MAKE) -C ./ft_printf

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c 
	$(CC) $(CFLAGS) -c -o $@ $^

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(FT_PRINTF) $(LIBFT) $(BONUS_OBJS_DIR) $(BONUS_OBJS_1) $(BONUS_OBJS_2)
	$(CC) $(CFLAGS) $(BONUS_OBJS_1) $(BONUS_OBJS_2) $(FT_PRINTF) $(LIBFT) -o $(BONUS_NAME)

$(BONUS_OBJS_DIR):
	mkdir -p $(BONUS_OBJS_DIR)

$(BONUS_OBJS_DIR)/%.o:$(BONUS_SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

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