/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:08:21 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/31 18:38:17 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

unsigned long	get_time(void)
{
	struct timeval	a;

	gettimeofday(&a, 0);
	return (((a.tv_sec * 1000000 + a.tv_usec) / 1000) % 1000000);
}

void	mutex_print(char *s, unsigned long time, t_param p)
{
	pthread_mutex_lock((p.write));
	if (!p.death || s[0] == 'h')
	{
		printf("%lu ", time);
		printf("%d ", p.n + 1);
		printf("%s\n", s);
	}
	pthread_mutex_unlock((p.write));
}

int	lock_mutex(pthread_mutex_t *left, pthread_mutex_t *right,
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
	mutex_print("has taken a fork", get_time(), p);
	return (1);
}

void	*phil_thread(void *param)
{
	t_param	p;

	p = *(t_param *)param;
	p.last_eat = get_time();
	while (get_time() < p.last_eat + p.t_die)
	{
		mutex_print("is thinking", get_time(), p);
		if (!lock_mutex(&p.ls[p.n], &p.ls[((p.n + 1) % p.total)], p)
			|| !lock_mutex(&p.ls[((p.n + 1) % p.total)], &p.ls[p.n], p))
			break ;
		mutex_print("is eating", get_time(), p);
		usleep(p.t_eat * 1000);
		p.last_eat = get_time();
		mutex_print("is sleeping", get_time(), p);
		pthread_mutex_unlock(&p.ls[p.n]);
		pthread_mutex_unlock(&p.ls[((p.n + 1) % p.total)]);
		if (p.t_slp > p.t_die)
			usleep(p.t_die * 1000 + 5 * 1000);
		else
			usleep(p.t_slp * 1000);
	}
	p.death = 1;
	if (p.n_eat)
		mutex_print("has died", get_time(), p);
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

int	allocate_all(pthread_t **pids,
	pthread_mutex_t **locks, t_param ***par, int n)
{
	*pids = malloc(sizeof(t_param *) * n);
	if (!pids)
		return (0);
	*locks = malloc(sizeof(pthread_mutex_t) * n);
	if (!locks)
	{
		free(*pids);
		return (0);
	}
	*par = malloc(sizeof(t_param *) * n);
	if (!par)
	{
		free(*pids);
		free(*locks);
		return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	pthread_t		*pids;
	pthread_mutex_t	*locks;
	t_param			**par;
	pthread_mutex_t	write;
	int				i;
	int				n;

	if ((ac != 5 && ac != 6) || !allocate_all(&pids, &locks, &par, inp(av[1])))
		return (0);
	i = -1;
	n = inp(av[1]);
	pthread_mutex_init(&(write), NULL);
	while (++i < n)
	{
		pthread_mutex_init(&(locks[i]), NULL);
		par[i] = malloc(sizeof(t_param));
		*(par[i]) = (t_param){.total = n, .n_eat = -1, .t_eat = inp(av[3]),
			.ls = locks, .n = i, .t_die = inp(av[2]), .t_slp = inp(av[4]),
			.write = &write};
		if (ac == 6)
			par[i]->n_eat = inp(av[5]);
	}
	while (--i >= 0)
		pthread_create(&(pids[i]), NULL, &phil_thread, par[i]);
	while (++i < n)
		pthread_join(pids[i], NULL);
	return (0);
}
