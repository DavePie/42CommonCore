CFILES	:= ft_printf.c write_types.c ft_print_helper.c write_helper.c
OBJECTS	:= $(patsubst %.c,%.o,$(CFILES))
LIB		:= ar -rcs
RM		:= rm -f
NAME	:= libftprintf.a
CC		:= gcc
INCDIR	:= .
CFLAGS	:= -Wall -Wextra -Werror -I$(INCDIR)
LIBZ	:= libft
all: $(NAME)

bonus: all

$(NAME): $(OBJECTS)
	cp $(LIBZ) $(NAME)
	$(LIB) $(NAME) $(OBJECTS)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

libft:
	make libft/Makefile

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re