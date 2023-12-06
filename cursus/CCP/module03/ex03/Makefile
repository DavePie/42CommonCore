# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 15:56:18 by dvandenb          #+#    #+#              #
#    Updated: 2023/12/06 15:42:19 by dvandenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES	:= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
RM		:= rm -f
NAME	:= FragTrap
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

run: $(NAME)
	./$(NAME)

.PHONY: clean fclean all re run