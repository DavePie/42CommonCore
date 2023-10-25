CFILES	:= find_best_insert.c operations_r.c operations.c push_sort.c push_swap.c stack.c is_sort.c parse_input.c
BONUSFILES := checker.c is_sort.c operations.c operations_r.c stack.c parse_input.c
RM		:= rm -f
NAME	:= push_swap
BONUS	:= checker
CC		:= gcc
INCDIR	:= .
LIBFT	:= libft/libft.a
CFLAGS	:= -Wall -Wextra -Werror -I$(INCDIR)

all: $(NAME)

bonus: $(BONUS)

$(BONUS) : $(BONUSFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUSFILES) $(LIBFT) -o $(BONUS)

$(NAME): $(CFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(CFILES) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	make -C libft clean
fclean: clean
	$(RM) $(NAME) $(BONUS)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re