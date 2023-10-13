CFILES	:= ft_printf.c write_types.c ft_print_helper.c write_helper.c
OBJECTS	:= $(patsubst %.c,%.o,$(CFILES))
LIB		:= ar -rcs
RM		:= rm -f
NAME	:= libftprintf.a
CC		:= gcc
INCDIR	:= .
CFLAGS	:= -Wall -Wextra -Werror -I$(INCDIR)


all: $(NAME)

$(NAME): $(OBJECTS)
	cp libft.a $(NAME)
	$(LIB) $(NAME) $(OBJECTS)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re