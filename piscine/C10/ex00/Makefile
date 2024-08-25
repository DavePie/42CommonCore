CC=gcc
CFLAGS=-Wall -Wextra -Werror
BINARY=ft_display_file
CFILES=ft_display_file.c
OBJECTS	= $(patsubst %.c,%.o,$(CFILES))
RM		= rm -f

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(BIN): $(CFILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(BINARY)

.PHONY: clean fclean all