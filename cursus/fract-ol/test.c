/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:36:27 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/25 18:54:29 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "mlx.h"
#include <unistd.h>
#include <math.h>

#define REP 40
#define HEIGHT 500
#define WIDTH 750

double zoom = 1;

typedef struct s_c
{
	int	c;
	int	i;
}	t_c;

int malen(double cn, double ci)
{
	double zn = 0;
	double zi = 0;
	int n = 0;
	while (sqrt(zn * zn + zi * zi) <= 2 && n < REP)
	{
		double temp = zn * zn - zi * zi + cn;
		
		zi = 2 * zn * zi + ci;
		zn = temp;
		n++;
	}
	return (n);
}


#include <stdio.h>
void	put_pixel(void *mlx_ptr, void *win_ptr, int i, int j, double zoom)
{
	double a = -2 * zoom + (((double) i) / WIDTH) * (1 + 2) * zoom;
	double b = -0.5 *zoom+ ((double) j) / HEIGHT * 1 *zoom;
	int m = malen(a,b);
	// printf("%f, %f, %d\n", a, b, malen(a,b));
	if (m == REP)
		mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFFFFF);
	else
		mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFFFFF / (REP - m));
}
void	*mlx_ptr;
void	*win_ptr;
void	put_set(void *mlx_ptr, void *win_ptr, double zoom)
{
	for (int i = 0; i < WIDTH; i++){
		for (int j = 0; j < HEIGHT; j++)
			put_pixel(mlx_ptr, win_ptr, i, j, zoom);
	}
}
int	deal_key(int key, void *param)
{
	write(1, "X", 1);
	printf("%d\n", key);
	if (key == 4)
		zoom *= 1.1;
	if (key == 5)
		zoom /= 1.1;
	if (key == 4 || key == 5)
		put_set(mlx_ptr, win_ptr, zoom);
	return (0);
}
int	main()
{
	

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "test");
	put_set(mlx_ptr, win_ptr, 1);
	mlx_mouse_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);	
	return (0);
}