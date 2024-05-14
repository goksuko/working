NAME	= pipex

NAME_B	= pipex_bonus

CC		= cc

CFLAGS	= -Werror -Wall -Wextra -fsanitize=address

RM		= rm -rf

SRCS	= $(shell find ./src -iname "*.c")

OBJS	= ${SRCS:.c=.o}

SRCS_B	= $(shell find ./src_bonus -iname "*.c")

OBJS_B	= ${SRCS_B:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_B) : $(OBJS_B)
	@$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

all : $(NAME)

fclean : clean
	@$(RM) $(NAME) $(NAME_B)

clean :
	@$(RM) $(OBJS) $(OBJS_B)

re : fclean all

bonus : $(NAME_B)