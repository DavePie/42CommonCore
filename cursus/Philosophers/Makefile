CFILES	:= main.c threads.c
RM		:= rm -f
NAME	:= philo
CC		:= gcc
INCDIR	:= -I .

CFLAGS	:= -Wall -Wextra -Werror $(INCDIR) $(LIB) #-fsanitize=address 

all: $(NAME) $(NAME2)

$(NAME): $(CFILE1) $(LIB)
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re