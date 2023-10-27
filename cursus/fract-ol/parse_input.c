/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:21:52 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/27 11:39:59 by dvandenb         ###   ########.fr       */
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
	if ((n == 3 || n == 4)
		&& !set_params(argv[n - 2], argv[n - 1], w) && print_usage())
		return (0);
	return (1);
}
