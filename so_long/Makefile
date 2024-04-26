NAME = so_long
#BONUS_NAME = checker
LIBFT = ./Libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
MINILIBX = ./include/libmlx42.a
HEAD = ../include/MLX42.h
HEAD2 = ../include/MLX42_int.h

SRCS_1 = \
			main.c \

SRCS_2 = \
			flood_fill.c \
			map_check.c \
			map_check2.c \
			utils.c \
			utils2.c \

SRCS_DIR = sources

OBJS_1 = $(SRCS_1:%.c=$(OBJS_DIR)/%.o)

OBJS_2 = $(SRCS_2:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = objects

BONUS_SRCS = \
			checker.c

BONUS_SRCS_DIR = sources/bonus

BONUS_OBJS = $(BONUS_SRCS:%.c=$(BONUS_OBJS_DIR)/%.o)

BONUS_OBJS_DIR = objects/bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

LFLAGS = -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(MINILIBX) $(FT_PRINTF) $(LIBFT) $(OBJS_DIR) $(OBJS_1) $(OBJS_2)
#	$(CC) $(LFLAGS) -g -fsanitize=address $(OBJS_1) $(OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(NAME)
#	$(CC) $(CFLAGS) $(LFLAGS) -g -fPIE -fPIC -fsanitize=address $(OBJS_1) $(OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(NAME)
	$(CC) $(CFLAGS) $(LFLAGS) -g $(OBJS_1) $(OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(NAME)
#	$(CC) $(LFLAGS) -g $(OBJS_1) $(OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./Libft

$(FT_PRINTF):
	$(MAKE) -C ./ft_printf

$(MINILIBX):
	./include/libmlx42.a

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
	$(MAKE) clean -C ./ft_printf

fclean:
	rm -f $(NAME) $(BONUS_NAME)
	rm -f ./a.out
	rm -f ./sources/a.out
	rm -f ./so_long
	rm -rf $(OBJS_DIR)
	$(MAKE) fclean -C ./Libft
	$(MAKE) fclean -C ./ft_printf

re: fclean all

.PHONY: all bonus clean fclean re
