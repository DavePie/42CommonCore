CC=gcc
INCDIR=.
CFLAGS=-Wall -Wextra -Werror -I$(INCDIR)
BINARY=rush-02
CFILES=read_str.c read_file.c write_number.c main.c helper_funcs.c
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