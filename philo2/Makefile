NAME = philo
LIBFT = ./Libft/libft.a
#SRCS = $(shell find ./src -iname "*.c")

SRCS = \
			main.c \
			table.c \
			errors.c \
			#utils.c \

SRCS_DIR = sources

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = objects

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
#CFLAGS += -g -pthread -fsanitize=thread 
#CFLAGS += -g -pthread -fsanitize=address

all: $(NAME)

#$(NAME): $(FT_PRINTF) $(LIBFT) $(OBJS_DIR) $(OBJS_1) $(OBJS_2)
$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
#	$(CC) $(LFLAGS) -g -fsanitize=address $(OBJS_1) $(OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(NAME)
#	$(CC) $(CFLAGS) $(LFLAGS) -g -fPIE -fPIC -fsanitize=address $(OBJS_1) $(OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(NAME)
#	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS_1) $(OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(NAME)
#	$(CC) $(CFLAGS) $(LFLAGS) -g -fPIE -fPIC $(OBJS_1) $(OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(NAME)
#	$(CC) $(CFLAGS) $(LFLAGS) -g $(OBJS_1) $(OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(NAME)
#	$(CC) $(LFLAGS) -g $(OBJS_1) $(OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./Libft

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(FT_PRINTF) $(LIBFT) $(OBJS_DIR) $(OBJS_2) $(BONUS_OBJS_DIR) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -g -fsanitize=address $(BONUS_OBJS) $(OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(BONUS_NAME)

$(BONUS_OBJS_DIR):
	mkdir -p $(BONUS_OBJS_DIR)

$(BONUS_OBJS_DIR)/%.o:$(BONUS_SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I $(HEAD)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) clean -C ./Libft

fclean:
	rm -f $(NAME) $(BONUS_NAME)
	rm -f ./a.out
	rm -f ./sources/a.out
	rm -f ./philo
	rm -rf $(OBJS_DIR)
	$(MAKE) fclean -C ./Libft

re: fclean all

.PHONY: all bonus clean fclean re
