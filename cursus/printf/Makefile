CFILES	:= ft_printf.c write_types.c
OBJECTS	:= $(patsubst %.c,%.o,$(CFILES))
LIB		:= gcc -W -W -W
RM		:= rm -f
BINARY	:= ft_printf

all: $(BINARY)

$(BINARY): 
	$(LIB) *.c libft.a

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJECTS) $(BOBJECTS)

fclean: clean
	$(RM) $(BINARY)

re: fclean all

.PHONY: clean fclean all