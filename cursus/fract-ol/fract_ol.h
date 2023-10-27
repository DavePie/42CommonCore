/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:38:27 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/27 18:18:09 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <mlx.h>
# include "keys.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

# define REP 80

# define HEIGHT 1000
# define WIDTH 1500

# define Z_RATE 1.3
# define M_RATE 25

# define MANDELBROT 0
# define JULIA 1
# define BURNING_SHIP 2

# define RED 0
# define BLUE 1
# define GREEN 2
# define MIX 3
# define PULSE 4
# define TRIP 5
# define TRIP2 6

typedef struct s_win
{
	void	*mlx;
	void	*win;

	int		frac;
	double	param1;
	double	param2;
	int		color;

	void	*img;
	char	*buffer;
	char	*pix;
	double	c_offset;

	double	zoom;
	double	offset_x;
	double	offset_y;
}	t_win;

int		get_frac(double a, double b, t_win *w);
void	print_fractal(t_win *w);
void	update_color(t_win *w, int i, int j, int m);

int		read_input(int n, char *argv[], t_win *w);
int		print_usage(void);
int		ft_strncmp(const char *s1, const char *s2, size_t a);

int		frame_event(t_win *w);
int		mouse_event(int key, int x, int y, t_win *w);
int		key_event(int key, t_win *w);

int		exit_fract(t_win *w);

#endif