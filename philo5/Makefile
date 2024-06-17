NAME = philo

SRCS = \
			main.c \
			table.c \
			check.c \
			clean.c \
			errors.c \
			philos.c \
			print.c \
			monitor.c \
			threads.c \
			threads_philo.c \
			forks.c \
			ft_atoi.c \
			ft_calloc.c \

SRCS_DIR = sources

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = objects

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -Wunreachable-code -Ofast
CFLAGS += -g -pthread
CFLAGS += -g
CFLAGS += -g -pthread -fsanitize=thread 
#CFLAGS += -g -pthread -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@echo "Compilation in Progress"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "********Completed********"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@echo "Cleaning in Progress"
	@rm -rf $(OBJS_DIR)
	@echo "Cleaning Completed"

fclean:
	@echo "Cleaning in Progress"
	@rm -f $(NAME) $(BONUS_NAME)
	@rm -f ./a.out
	@rm -f ./sources/a.out
	@rm -f ./philo
	@rm -rf $(OBJS_DIR)
	@echo "***Cleaning Completed***"
	@echo ""

re: fclean all

.PHONY: all clean fclean re
