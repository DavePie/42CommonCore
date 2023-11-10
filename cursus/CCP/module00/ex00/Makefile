# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 15:56:18 by dvandenb          #+#    #+#              #
#    Updated: 2023/11/09 14:22:56 by dvandenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES	:= megaphone.cpp
RM		:= rm -f
NAME	:= megaphone
CC		:= c++
INCDIR	:= -I .

CFLAGS	:= -Wall -Wextra -Werror $(INCDIR) -std=c++98 #-fsanitize=address 

all: $(NAME)

$(NAME): $(CFILES) $(LIB)
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re