/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:21:52 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/01 12:51:39 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	set_fractal(char *name, t_win *w)
{
	if (!ft_strncmp("mandelbrot", name, 11))
		w->frac = MANDELBROT;
	else if (!ft_strncmp("julia", name, 6))
		w->frac = JULIA;
	else if (!ft_strncmp("burning_ship", name, 6))
		w->frac = BURNING_SHIP;
	else
		return (0);
	return (1);
}

int	set_color_type(char *color, t_win *w)
{
	if (!ft_strncmp("red", color, 11))
		w->color = RED;
	else if (!ft_strncmp("blue", color, 5))
		w->color = BLUE;
	else if (!ft_strncmp("green", color, 5))
		w->color = GREEN;
	else if (!ft_strncmp("mix", color, 4))
		w->color = MIX;
	else if (!ft_strncmp("pulse", color, 6))
		w->color = PULSE;
	else if (!ft_strncmp("trip", color, 5))
		w->color = TRIP;
	else if (!ft_strncmp("trip2", color, 6))
		w->color = TRIP2;
	else
		return (0);
	return (1);
}

double	ft_atoi(const char *s)
{
	double	ans;
	long	count;
	int		is_neg;

	ans = 0;
	count = 10;
	is_neg = *s == '-';
	if (*s == '-' || *s == '+')
		s++;
	while ((*s == '0' || *s == '1') && ans < 2)
		ans += *(s++) - '0';
	if ((*s != '.' && *s) || ans >= 2)
		return (2);
	if (!*s)
		return (ans * (1 - 2 * is_neg));
	s++;
	while (*s >= '0' && *s <= '9')
	{
		ans += (double)(*(s++) - '0') / count;
		count *= 10;
	}
	if (*s)
		return (2);
	return (ans * (1 - 2 * is_neg));
}

int	set_params(char *p1, char *p2, t_win *w)
{
	w->param1 = ft_atoi(p1);
	w->param2 = ft_atoi(p2);
	if (w->param1 == 2 || w->param2 == 2)
		return (0);
	return (1);
}

int	read_input(int n, char *argv[], t_win *w)
{
	if ((!n || !set_fractal(argv[0], w)) && print_usage())
		return (0);
	if ((n == 2 || n == 4) && !set_color_type(argv[1], w) && print_usage())
		return (0);
	if ((n == 3 || n == 4)
		&& !set_params(argv[n - 2], argv[n - 1], w) && print_usage())
		return (0);
	w->mlx = mlx_init();
	return (1);
}
