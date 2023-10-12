CC		:= gcc
INCDIR	:= .
CFLAGS	:= -Wall -Wextra -Werror -I$(INCDIR)
BINARY	:= libft.a
BCFILES	:= $(wildcard *.c)
CFILES	:= $(filter-out $(wildcard ft_lst*.c), $(BCFILES))
OBJECTS	:= $(patsubst %.c,%.o,$(CFILES))
BOBJECTS:= $(patsubst %.c,%.o,$(BCFILES))
LIB		:= ar -rcs
RM		:= rm -f

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(LIB) $@ $^

bonus: $(BINARY) ${BOBJECTS}
	$(LIB) -r $(BINARY) ${BOBJECTS}

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJECTS) $(BOBJECTS)

fclean: clean
	$(RM) $(BINARY)

re: fclean all

.PHONY: clean fclean all bonus