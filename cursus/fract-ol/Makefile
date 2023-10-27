CFILES	:= events.c fract_colors.c fract-ol.c fractals.c parse_input.c
RM		:= rm -f
NAME	:= fractol
CC		:= gcc
INCDIR	:= -I . -I mlx

LIB	:= libmlx.a
LIBDIR := mlx/$(LIB)
CFLAGS	:= -Wall -Wextra -Werror $(INCDIR)

all: $(NAME)

$(NAME): $(CFILES) $(LIBDIR)
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME) -L mlx -lmlx -framework OpenGL -framework Appkit

$(LIBDIR):
	make -C mlx

clean:
	make -C mlx clean

fclean: clean
	$(RM) $(NAME) $(BONUS)
	$(RM) $(LIBDIR)
	make -C mlx clean

re: fclean all

.PHONY: clean fclean all re