CFILES	:= find_best_insert.c operations_r.c operations.c push_sort.c push_swap.c stack.c

RM		:= rm -f
NAME	:= push_swap
CC		:= gcc
INCDIR	:= .
CFLAGS	:= -Wall -Wextra -Werror -I$(INCDIR)

all: $(NAME)

bonus: all

$(NAME): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME)


$(LIBZ):
	make -C libft

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re