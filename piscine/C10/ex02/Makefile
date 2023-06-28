CC=gcc
INCDIR=.
CFLAGS=-Wall -Wextra -Werror -I$(INCDIR)
BINARY=ft_tail
CFILES=ft_tail.c ft_helper.c
OBJECTS	= $(patsubst %.c,%.o,$(CFILES))
RM		= rm -f

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(BINARY)

.PHONY: clean fclean all