CC=gcc
INCDIR=.
CFLAGS=-Wall -Wextra -Werror -I$(INCDIR)
BINARY=libft.a
SRC_DIR = Part1
CFILES=$(wildcard $(SRC_DIR)/*.c)
OBJECTS	= $(patsubst %.c,%.o,$(CFILES))
RM		= rm -f

all: $(BINARY)

$(BINARY): $(OBJECTS)
	ar rc $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(BINARY)

.PHONY: clean fclean all