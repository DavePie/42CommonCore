/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:12:58 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/27 18:11:39 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	set_color(char *pix, int x, int y, int color)
{
	pix[(x + y * WIDTH) * 4 + 0] = color;
	pix[(x + y * WIDTH) * 4 + 1] = color >> 8;
	pix[(x + y * WIDTH) * 4 + 2] = color >> 16;
	pix[(x + y * WIDTH) * 4 + 3] = color >> 24;
	return (1);
}

void	update_color(t_win *w, int i, int j, int m)
{
	if (m == REP && set_color(w->pix, i, j, 0))
		return ;
	if (w->color == RED)
		set_color(w->pix, i, j, (255 * m / REP << 16));
	if (w->color == GREEN)
		set_color(w->pix, i, j, (255 * m / REP << 8));
	if (w->color == BLUE)
		set_color(w->pix, i, j, (255 * m / REP));
	if (w->color == MIX)
		set_color(w->pix, i, j, (0xFFFFFF - 0xFFFFFF * ((double)m / REP)));
	if (w->color == PULSE || w->color == TRIP)
		set_color(w->pix, i, j, ((int)(w->c_offset * 255 * m / REP) << 16)
			+ ((int)((1 - w->c_offset) * 255 * m / REP) << 8));
	if (w->color == TRIP2)
		set_color(w->pix, i, j,
			((int)((1 - w->c_offset) * 255 * m / REP) << 16) + (0xFF << 24));
}

void	put_pixel(t_win *w, int i, int j)
{
	int	m;

	m = get_frac(-2 * w->zoom + (i + w->offset_x / w->zoom)
			/ WIDTH * 4 * w->zoom, -1.5 * w->zoom
			+ (j + w->offset_y / w->zoom) / HEIGHT * 3 * w->zoom, w);
	w->buffer[i + j * WIDTH] = m;
	update_color(w, i, j, m);
}

void	print_fractal(t_win *w)
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
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
}
