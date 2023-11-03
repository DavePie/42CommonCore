/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:08:21 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/03 10:55:01 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

unsigned long	get_time(void)
{
	struct timeval	a;

	gettimeofday(&a, 0);
	return (((a.tv_sec * 1000000 + a.tv_usec)));
}

int	inp(char *c)
{
	long	a;

	a = 0;
	while (*c >= '0' && *c <= '9' && a <= 2147483647)
		a = a * 10 + *c++ - '0';
	if (*c || a > 2147483647)
		return (-1);
	return ((int)a);
}

int	allocate_all(pthread_t **pids,
	pthread_mutex_t **locks, t_param **par, int n)
{
	*pids = malloc(sizeof(t_param *) * n);
	if (!pids)
		return (0);
	*locks = malloc(sizeof(pthread_mutex_t) * (n + 1));
	if (!locks)
	{
		free(*pids);
		return (0);
	}
	*par = malloc(sizeof(t_param) * n);
	if (!par)
	{
		free(*pids);
		free(*locks);
		return (0);
	}
	return (1);
}

int	init_pthreads(t_param *par, pthread_mutex_t *locks, int ac, char *av[])
{
	int				i;
	int				n;
	int				*is_dead;

	is_dead = malloc(sizeof(int));
	*is_dead = 0;
	n = inp(av[1]);
	i = -1;
	pthread_mutex_init(&(locks[n]), NULL);
	while (++i < n)
	{
		pthread_mutex_init(&(locks[i]), NULL);
		par[i] = (t_param){.total = n, .n_eat = -1,
			.t_eat = inp(av[3]) * 1000, .ls = locks, .n = i,
			.t_die = inp(av[2]) * 1000, .t_slp = inp(av[4]) * 1000,
			.write = &(locks[n]), .death = is_dead};
		if (ac == 6)
			par[i].n_eat = inp(av[5]);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	pthread_t		*pids;
	pthread_mutex_t	*locks;
	t_param			*par;
	int				i;
	int				n;

	if ((ac != 5 && ac != 6) || inp(av[1]) == -1 || inp(av[2]) == -1
		|| inp(av[3]) == -1 || inp(av[4]) == -1
		|| (ac == 6 && inp(av[5]) == -1)
		|| !allocate_all(&pids, &locks, &par, inp(av[1])))
		return (0);
	i = -1;
	n = inp(av[1]);
	init_pthreads(par, locks, ac, av);
	while (++i < n)
		pthread_create(&(pids[i]), NULL, &phil_thread, &(par[i]));
	while (--i >= 0)
		pthread_join(pids[i], NULL);
	free(par[0].death);
	while (++i <= n)
		pthread_mutex_destroy(&locks[i]);
	free(par);
	free(pids);
	free(locks);
	return (0);
}
