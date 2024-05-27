CC=gcc
INCDIR=.
CFLAGS=-Wall -Wextra -Werror -I$(INCDIR)
BINARY=ft_hexdump
CFILES=hexdump.c get_len.c writehex.c
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