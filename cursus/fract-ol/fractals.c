/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:59:21 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/27 11:29:39 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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
