/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:36:27 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/26 18:38:07 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	exit_fract(t_win *w)
{
	if (!w)
		exit(0);
	if (w->img)
		mlx_destroy_image(w->mlx, w->img);
	if (w->win_ptr && w->mlx)
		mlx_destroy_window(w->mlx, w->win_ptr);
	exit(0);
	return (0);
}

int	get_julia(double cn, double ci, double zn, double zi)
{
	int		n;
	double	temp;

	n = 0;
	while (zn * zn + zi * zi <= 4 && n < REP)
	{
		temp = zn * zn - zi * zi + cn;
		zi = 2 * zn * zi + ci;
		zn = temp;
		n++;
	}
	return (n);
}

int	try_paint(double cn, double ci, double zn, double zi)
{
	int		n;
	double	temp;
	
	n = 0;
	while (zn * zn + zi * zi <= 4 && n < REP)
	{
		temp = zn * zn - zi * zi * zi + cn;
		zi = 2 * zn * zi + ci;
		zn = temp;
		n++;
	}
	return (n);
}

int	interest_repeat(double cn, double ci, double zn, double zi)
{
	int		n;
	double	temp;
	
	n = 0;
	while (zn * zn + zi * zi <= 4 && n < REP)
	{
		temp = zn * zn - 3 * zi * zi * zn + cn;
		zi = 3 * zn * zn * zi + zi * zi + ci;
		zn = temp;
		n++;
	}
	return (n);
}

void	set_color(char *pix, int x, int y, int color)
{
	pix[(x + y * WIDTH) * 4 + 0] = color;
	pix[(x + y * WIDTH) * 4 + 1] = color >> 8;
	pix[(x + y * WIDTH) * 4 + 2] = color >> 16;
	pix[(x + y * WIDTH) * 4 + 3] = color >> 24;
}

int	get_frac(double a, double b, t_win *w)
{
	if (w->frac == MANDELBROT)
		return (get_julia(a, b, 0, 0));
	else if (w->frac == JULIA)
		return (get_julia(a, b, w->param1, w->param2));
	else if (w->frac == PAINT)
		return (try_paint(a, b, w->param1, w->param2));
	return (interest_repeat(a, b, w->param1, w->param2));
}

void	put_pixel(t_win *w, int i, int j)
{
	int	m;

	m = get_frac(-2 * w->zoom + (i + w->offset_x / w->zoom)
			/ WIDTH * 4 * w->zoom, -1.5 * w->zoom
			+ (j + w->offset_y / w->zoom) / HEIGHT * 3 * w->zoom, w);
	w->buffer[i + j * WIDTH] = m;
	if (m == REP)
		set_color(w->pix, i, j, 0xFFFFFF);
	else
		set_color(w->pix, i, j, (255 * m / REP << 8));
}

void	put_set(t_win *w)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			put_pixel(w, i, j);
	}
	mlx_put_image_to_window(w->mlx, w->win_ptr, w->img, 0, 0);
}

int	mouse_event(int key, int x, int y, t_win *w)
{
	if (key == 1)
	{
		w->param1 = (double)x / WIDTH;
		w->param2 = (double)y / HEIGHT;
		put_set(w);
	}
	if (key == M_UP)
		w->zoom *= Z_RATE;
	if (key == M_DOWN)
	{
		w->zoom /= Z_RATE;
		w->offset_x += (x - WIDTH / 2) * w->zoom / 3.35;
		w->offset_y += (y - HEIGHT / 2) * w->zoom / 3.35;
	}
	if (key == M_UP || key == M_DOWN)
		put_set(w);
	return (0);
}

int	key_event(int key, t_win *w)
{
	double	offset;

	offset = 25 * w->zoom;
	if (key == K_LEFT)
		w->offset_x -= M_RATE * w->zoom;
	if (key == K_RIGHT)
		w->offset_x += M_RATE * w->zoom;
	if (key == K_DOWN)
		w->offset_y += M_RATE * w->zoom;
	if (key == K_UP)
		w->offset_y -= M_RATE * w->zoom;
	if (key >= K_LEFT && key <= K_UP)
		put_set(w);
	if (key == K_ESC)
		exit_fract(w);
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

int	print_usage()
{
	write(1, "            ~~Fracking Oil (fract-ol)~~\n", 40);
	write(1, "  Usage: ./fractol <fractal name> <fractal color> <fractal param>\n\n", 67);
	write(1, "  <fractal name> : mandelbrot, julia, paint, complex_cubic\n", 59);
	write(1, "  <fractal color> : red, blue, green, mix, pulse\n", 49);
	write(1, "  <fractal param> : <digit>.<digit> <digit>.<digit>\n\n", 53);
	write(1, "  note: mandelbrot ignores fractal parameters\n", 46);
	write(1, "  example: ./fractol julia red 0.5 0.8\n", 39);
	return (1);
}

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

int	set_fractal(char *name, t_win *w)
{
	if (!ft_strncmp("mandelbrot", name, 11))
		w->frac = MANDELBROT;
	else if (!ft_strncmp("julia", name, 6))
		w->frac = JULIA;
	else if (!ft_strncmp("paint", name, 6))
		w->frac = PAINT;
	else if (!ft_strncmp("complex_cubic", name, 14))
		w->frac = COMPLEX_CUBE;
	else
		return (0);
	return (1);
}

int	set_color_type(char *color, t_win *w)
{
	if (!ft_strncmp("red", color, 11))
		w->color = RED;
	else if (!ft_strncmp("blue", color, 6))
		w->color = BLUE;
	else if (!ft_strncmp("green", color, 6))
		w->color = GREEN;
	else if (!ft_strncmp("mix", color, 14))
		w->color = MIX;
	else if (!ft_strncmp("pulse", color, 14))
		w->color = PULSE;
	else
		return (0);
	return (1);
}

int	set_params(char *p1, char *p2, t_win *w)
{
	if (*p1 < '0' || *p1 > '9' || p1[1] != '.'
		|| p1[2] < '0' || p1[2] > '9' || p1[3])
		return (0);
	if (*p2 < '0' || *p2 > '9' || p2[1] != '.'
		|| p2[2] < '0' || p2[2] > '9' || p2[3])
		return (0);
	w->param1 = p1[0] - '0' + (double)(p1[2] - '0') / 10;
	w->param2 = p2[0] - '0' + (double)(p2[2] - '0') / 10;
	return (1);
}

int	read_input(int n, char *argv[], t_win *w)
{
	if ((!n || !set_fractal(argv[0], w)) && print_usage())
		return (0);
	if ((n == 2 || n == 4) && !set_color_type(argv[1], w) && print_usage())
		return (0);
	if ((n == 3 || n == 5) && !set_params(argv[n - 2], argv[n - 1], w) && print_usage())
		return (0);
	return (1);
}

int	main(int argn, char*argv[])
{
	t_win	w;

	w = (t_win){.mlx = mlx_init(), .zoom = 1};
	if (!w.mlx || !read_input(--argn, ++argv, &w))
		exit_fract(&w);
	w.win_ptr = mlx_new_window(w.mlx, WIDTH, HEIGHT, "fract_ol");
	if (!w.win_ptr)
		exit_fract(&w);
	create_image(&w);
	mlx_do_key_autorepeaton(w.mlx);
	put_set(&w);
	mlx_mouse_hook(w.win_ptr, mouse_event, &w);
	mlx_key_hook(w.win_ptr, key_event, &w);
	mlx_hook(w.win_ptr, B_EXIT, 0, exit_fract, &w);
	mlx_loop(w.mlx);
	return (0);
}
