CC		= gcc
CODEDIR	= srcs
INCDIR	= includes
CFLAGS	= -Wall -Wextra -Werror -I $(INCDIR)
CFILES	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
LIBRARY	= libft.a
OBJECTS	= $(patsubst %.c,%.o,$(CFILES))
RM		= rm -f

all: $(LIBRARY)

$(LIBRARY) : $(OBJECTS)
	ar rcs $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(LIBRARY)

re: fclean all

.PHONY: clean fclean re all