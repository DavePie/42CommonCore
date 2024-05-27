/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:59:21 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/27 18:20:45 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	get_julia(double cn, double ci, double zn, double zi)
{
	int		n;
	double	temp;

	zi = -zi;
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

int	get_burning_ship(double cn, double ci, double zn, double zi)
{
	int		n;
	double	temp;
	double	x;
	double	y;

	n = 0;
	x = zn * (1 + cn);
	y = zi * (1 + ci);
	n += 0 * (cn + ci);
	while (zn * zn + zi * zi < 4 && n < REP)
	{
		temp = zn * zn - zi * zi + x;
		zi = fabs(2 * zn * zi) + y;
		zn = temp;
		n++;
	}
	return (n);
}

int	get_frac(double a, double b, t_win *w)
{
	if (w->frac == MANDELBROT)
		return (get_julia(a, b, 0, 0));
	else if (w->frac == JULIA)
		return (get_julia(w->param1, w->param2, a, b));
	return (get_burning_ship(w->param1, w->param2, a, b));
}
