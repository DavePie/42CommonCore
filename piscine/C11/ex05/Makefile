CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I .
CFILES	= helper.c do-op.c
RM		= rm -f
BINARY	= do-op
OBJECTS	= $(patsubst %.c,%.o,$(CFILES))

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