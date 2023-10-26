/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:38:27 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/26 18:11:57 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# include "mlx.h"
# include "keys.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define FRACT_OL_H

# define REP 60

# define HEIGHT 1000
# define WIDTH 1500

# define Z_RATE 1.3
# define M_RATE 25

# define MANDELBROT 0
# define JULIA 1
# define PAINT 2
# define COMPLEX_CUBE 3

# define RED 0
# define BLUE 1
# define GREEN 2
# define MIX 3
# define PULSE 4

typedef struct s_win
{
	void	*mlx;
	void	*win_ptr;

	int		frac;
	double	param1;
	double	param2;
	int		color;

	void	*img;
	char	*buffer;
	char	*pix;

	double	zoom;
	double	offset_x;
	double	offset_y;
}	t_win;
#endif