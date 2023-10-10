CC		= gcc
INCDIR	= .
CFLAGS	= -Wall -Wextra -Werror -I$(INCDIR)
BINARY	= libft.a
SRC_DIR = Part1
B_DIR	= Bonus
CFILES	= $(wildcard $(SRC_DIR)/*.c)
BCFILES	= $(wildcard $(B_DIR)/*.c)
OBJECTS	= $(patsubst %.c,%.o,$(CFILES))
BOBJECTS= $(patsubst %.c,%.o,$(BCFILES))
RM		= rm -f

all: $(BINARY)

$(BINARY): $(OBJECTS)
	ar rc $@ $^

bonus: $(BOBJECTS) $(OBJECTS)
	ar rc $(BINARY) $^

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJECTS) $(BOBJECTS)

fclean: clean
	$(RM) $(BINARY)

.PHONY: clean fclean all bonus