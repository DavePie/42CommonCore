CC=gcc
CFLAGS=-Wall -Wextra -Werror
BINARY=ft_cat
CFILES=ft_cat.c
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