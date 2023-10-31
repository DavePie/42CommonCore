/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:08:21 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/31 17:31:52 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

unsigned long	get_time(void)
{
	struct timeval	a;

	gettimeofday(&a, 0);
	return (((a.tv_sec * 1000000 + a.tv_usec) / 1000) % 1000000);
}

int	unlock_mutex(pthread_mutex_t *left, pthread_mutex_t *right,
	t_param p)
{
	if (p.n % 2)
		pthread_mutex_lock(left);
	else
		pthread_mutex_lock(right);
	if (get_time() > p.last_eat + p.t_die)
	{
		if (p.n % 2)
			pthread_mutex_unlock(left);
		else
			pthread_mutex_unlock(right);
		return (0);
	}
	printf("\n%lu %d has taken a fork\n", get_time(), p.n);
	return (1);
}

void	*phil_thread(void *param)
{
	t_param	p;

	p = *(t_param *)param;
	p.last_eat = get_time();
	while (get_time() < p.last_eat + p.t_die)
	{
		printf("\n%lu %d is thinking\n", get_time(), p.n);
		if (!unlock_mutex(&p.ls[p.n], &p.ls[((p.n + 1) % p.total)], p)
			|| !unlock_mutex(&p.ls[((p.n + 1) % p.total)], &p.ls[p.n], p))
			break ;
		printf("\n%lu %d is eating\n", get_time(), p.n);
		usleep(p.t_eat * 1000);
		p.last_eat = get_time();
		printf("\n%lu %d is sleeping\n", get_time(), p.n);
		pthread_mutex_unlock(&p.ls[p.n]);
		pthread_mutex_unlock(&p.ls[((p.n + 1) % p.total)]);
		if (p.t_slp > p.t_die)
			usleep(p.t_die * 1000 + 5 * 1000);
		else
			usleep(p.t_slp * 1000);
	}
	if (p.n_eat)
		printf("\n%lu %d has died (%lu)\n", get_time(), p.n, p.last_eat);
	return (0);
}

int	inp(char *c)
{
	long	a;

	a = 0;
	while (*c >= '0' && *c <= '9' && a <= 2147483647)
		a = a * 10 + *c++ - '0';
	if (*c || a > 2147483647)
		return (0);
	return ((int)a);
}

int	main(int argc, char *argv[])
{
	pthread_t		*pids;
	pthread_mutex_t	*locks;
	t_param			**par;
	int				i;
	int				n;

	if (argc != 5 && argc != 6)
		return (0);
	i = -1;
	n = inp(argv[1]);
	par = malloc(sizeof(t_param *) * n);
	locks = malloc(sizeof(pthread_mutex_t) * n);
	pids = malloc(sizeof(pthread_t) * n);
	while (++i < n)
	{
		pthread_mutex_init(&(locks[i]), NULL);
		par[i] = malloc(sizeof(t_param));
		*(par[i]) = (t_param){.total = n, .n_eat = -1, .t_eat = inp(argv[3]),
			.ls = locks, .n = i, .t_die = inp(argv[2]), .t_slp = inp(argv[4])};
		if (argc == 6)
			par[i]->n_eat = inp(argv[5]);
	}
	while (--i >= 0)
		pthread_create(&(pids[i]), NULL, &phil_thread, par[i]);
	while (++i < n)
		pthread_join(pids[i], NULL);
	return (0);
}
