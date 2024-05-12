NAME = so_long_bonus
LIBFT = ./Libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
MLX = ./MLX42
MINILIBX = $(MLX)/build/libmlx42.a
HEAD = ../include/MLX42.h
HEAD2 = ../include/MLX42_int.h

SRCS_1 = \
			main.c \

SRCS_2 = \
			flood_fill.c \
			game.c \
			images.c \
			keyboard.c \
			map.c \
			map_check.c \
			map_check2.c \
			utils_game.c \
			utils.c \
			utils2.c \

SRCS_DIR = sources

OBJS_1 = $(SRCS_1:%.c=$(OBJS_DIR)/%.o)

OBJS_2 = $(SRCS_2:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = objects

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
CFLAGS += -g

LFLAGS = -ldl  -L/lib/x86_64-linux-gnu -lglfw -pthread -lm -L./MLX42/build/ -lmlx42

all: mlx42 $(NAME)

mlx42:
	cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4

$(NAME): $(MINILIBX) $(FT_PRINTF) $(LIBFT) $(OBJS_DIR) $(OBJS_1) $(OBJS_2)
	$(CC) $(CFLAGS) $(LFLAGS) -g -fPIE -fPIC -fsanitize=address $(OBJS_1) $(OBJS_2) $(MINILIBX) $(FT_PRINTF) $(LIBFT) -o $(NAME)
	@echo ""
	@echo *******Completed********

$(LIBFT):
	$(MAKE) -C ./Libft

$(FT_PRINTF):
	$(MAKE) -C ./ft_printf

$(MINILIBX):
	${MAKE} -C ./MLX42/build

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) clean -C ./Libft
	$(MAKE) clean -C ./ft_printf

fclean:
	rm -f $(NAME)
	rm -f ./a.out
	rm -f ./sources/a.out
	rm -f ./so_long
	rm -rf $(OBJS_DIR)
	$(MAKE) fclean -C ./Libft
	$(MAKE) fclean -C ./ft_printf

re: fclean all

.PHONY: all bonus clean fclean re
