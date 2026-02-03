NAME = pipex

LIBFT = ./lib/libft

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

AR = ar rcs

SRCS = pipex.c ./src/pipex_utils.c ./src/init.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME) libft.a
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
