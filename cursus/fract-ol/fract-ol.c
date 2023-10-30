/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:36:27 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/30 10:45:57 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t a)
{
	while (*s1 != '\0' && *s1 == *s2 && a > 0)
	{
		s1++;
		s2++;
		a--;
	}
	if (a == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	exit_fract(t_win *w)
{
	if (!w)
		exit(0);
	if (w->img)
		mlx_destroy_image(w->mlx, w->img);
	if (w->buffer)
		free(w->buffer);
	if (w->win && w->mlx)
		mlx_destroy_window(w->mlx, w->win);
	exit(0);
	return (0);
}

void	create_image(t_win *w)
{
	int	bits;
	int	size;
	int	edian;

	w->img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	w->buffer = malloc(sizeof(int) * WIDTH * HEIGHT);
	if (!w->img || !w->buffer)
		exit_fract(w);
	w->pix = mlx_get_data_addr(w->img, &bits, &size, &edian);
}

int	print_usage(void)
{
	write(1, "            ~~Fracking Oil (fract-ol)~~\n", 40);
	write(1, "  Usage: ./fractol", 18);
	write(1, " <fractal name> <fractal color> <fractal param>\n\n", 49);
	write(1, "  <fractal name> : mandelbrot, julia, burning_ship\n", 51);
	write(1, "  <fractal color> : red, blue,", 30);
	write(1, " green, mix, pulse, trip, trip2\n", 32);
	write(1, "  <fractal param> : <number1> <number2>\n\n", 41);
	write(1, "  note: mandelbrot ignores fractal parameters\n", 46);
	write(1, "  example: ./fractol julia red 0.5 0.8\n", 39);
	return (1);
}

int	main(int argn, char*argv[])
{
	t_win	w;

	w = (t_win){.mlx = mlx_init(), .zoom = 1};
	if (!w.mlx || !read_input(--argn, ++argv, &w))
		exit_fract(&w);
	w.win = mlx_new_window(w.mlx, WIDTH, HEIGHT, "fract_ol");
	if (!w.win)
		exit_fract(&w);
	create_image(&w);
	mlx_do_key_autorepeaton(w.mlx);
	print_fractal(&w);
	mlx_mouse_hook(w.win, mouse_event, &w);
	mlx_key_hook(w.win, key_event, &w);
	mlx_hook(w.win, B_EXIT, 0, exit_fract, &w);
	mlx_loop_hook(w.mlx, frame_event, &w);
	mlx_loop(w.mlx);
	return (0);
}
