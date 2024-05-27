CFILES	:= ft_printf.c write_types.c ft_print_helper.c write_helper.c
OBJECTS	:= $(patsubst %.c,%.o,$(CFILES))
LIB		:= ar -rcs
RM		:= rm -f
NAME	:= libftprintf.a
CC		:= gcc
INCDIR	:= .
CFLAGS	:= -Wall -Wextra -Werror -I$(INCDIR)
LIBZ	:= ./libft/libft.a
all: $(NAME)

bonus: all

$(NAME): $(OBJECTS) $(LIBZ)
	cp $(LIBZ) $(NAME)
	$(LIB) $(NAME) $(OBJECTS)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(LIBZ):
	make -C libft

clean:
	$(RM) $(OBJECTS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: clean fclean all re