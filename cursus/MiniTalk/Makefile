CFILE1	:= server.c
CFILE2	:= client.c
RM		:= rm -f
NAME	:= server
NAME2	:= client
CC		:= gcc
INCDIR	:= -I . -I mlx

LIB	:= printf/libftprintf.a
CFLAGS	:= -Wall -Wextra -Werror $(INCDIR) $(LIB) -fsanitize=address 

all: $(NAME) $(NAME2)

$(NAME): $(CFILE1) $(LIB)
	$(CC) $(CFLAGS) $(CFILE1) -o $(NAME)

$(NAME2): $(CFILE2) $(LIB)
	$(CC) $(CFLAGS) $(CFILE2) -o $(NAME2)

$(LIB):
	make -C printf

clean:
	make -C printf clean

fclean: clean
	$(RM) $(NAME) $(NAME2)
	make -C printf fclean

re: fclean all

.PHONY: clean fclean all re