CC		= gcc
SRCS	= main.c read_file.c find_square.c setup_map.c
INC		= BSQ.h
CFLAGS	= -Wall -Wextra -Werror -I ${INC}
BIN 	= bsq
OBJS	= main.o read_file.o find_square.o setup_map.o
RM		= rm -f

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(BIN)
