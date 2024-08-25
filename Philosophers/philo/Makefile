# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 15:56:18 by dvandenb          #+#    #+#              #
#    Updated: 2023/11/07 13:35:07 by dvandenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES	:= main.c threads.c sleep.c
RM		:= rm -f
NAME	:= philo
CC		:= gcc
INCDIR	:= -I .

CFLAGS	:= -Wall -Wextra -Werror $(INCDIR) $(LIB) #-fsanitize=address 

all: $(NAME)

$(NAME): $(CFILES) $(LIB)
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re