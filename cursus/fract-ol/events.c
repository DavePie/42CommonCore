/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:15:08 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/27 11:29:43 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	frame_event(t_win *w)
{
	int	i;
	int	j;

	if (w->color != PULSE && w->color != TRIP)
		return (0);
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			update_color(w, i, j, w->buffer[i + j * WIDTH]);
	}
	if (w->color == PULSE)
		w->c_offset += 0.01;
	if (w->color == TRIP)
		w->c_offset += 0.05;
	if ((w->c_offset > 1 && w->color == PULSE)
		|| (w->c_offset > 255 && w->color == TRIP))
		w->c_offset -= 1;
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	return (0);
}

int	mouse_event(int key, int x, int y, t_win *w)
{
	if (key == 1)
	{
		w->param1 = (double)x / WIDTH;
		w->param2 = (double)y / HEIGHT;
		print_fractal(w);
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
		print_fractal(w);
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
		print_fractal(w);
	if (key == K_ESC)
		exit_fract(w);
	return (0);
}
