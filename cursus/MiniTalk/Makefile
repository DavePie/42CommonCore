CFILE1	:= server.c
CFILE2	:= client.c
RM		:= rm -f
NAME	:= server
NAME2	:= client
CC		:= gcc
INCDIR	:= -I . -I mlx

LIB	:= libmlx.a
LIBDIR := mlx/$(LIB)
CFLAGS	:= -Wall -Wextra -Werror $(INCDIR) libftprintf.a -fsanitize=address 

all: $(NAME) $(NAME2)

$(NAME): $(CFILE1)
	$(CC) $(CFLAGS) $(CFILE1) -o $(NAME)

$(NAME2): $(CFILE2)
	$(CC) $(CFLAGS) $(CFILE2) -o $(NAME2)

clean:

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY: clean fclean all re