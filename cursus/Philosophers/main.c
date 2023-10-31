/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:08:21 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/31 14:43:26 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

unsigned long	get_time()
{
	struct timeval a;

	gettimeofday(&a, 0);
	return (((a.tv_sec * 1000000 + a.tv_usec)) / 1000);
}

int	unlock_mutex(pthread_mutex_t *left, pthread_mutex_t *right,
	int n, unsigned long death_time)
{
	if (n % 2)
		pthread_mutex_lock(left);
	else
		pthread_mutex_lock(right);
	if (get_time() > death_time)
	{
		if (n % 2)
			pthread_mutex_unlock(left);
		else
			pthread_mutex_unlock(right);
		return (0);
	}
	printf("\n%lu %d has taken a fork\n", get_time()/100 % 10000, n);
	return (1);
}

void	*try_this(void *param)
{
	t_param	p = *(t_param*)param;

	p.last_eat = get_time();
	while (get_time() < p.last_eat + p.time_die)
	{
		printf("\n%lu %d is thinking\n", get_time()/100 % 10000, p.n);
		if (!unlock_mutex(&p.locks[p.n], &p.locks[((p.n + 1) % p.total)], p.n, p.last_eat + p.time_die)
		|| !unlock_mutex(&p.locks[((p.n + 1) % p.total)], &p.locks[p.n], p.n, p.last_eat + p.time_die))
		{
			pthread_mutex_unlock(&p.locks[p.n]); 
			pthread_mutex_unlock(&p.locks[((p.n + 1) % p.total)]);
			break;
		}
		printf("\n%lu %d is eating\n", get_time()/100 % 10000, p.n);
		usleep(p.time_eat * 1000);
		p.last_eat = get_time();
		pthread_mutex_unlock(&p.locks[p.n]); 
		pthread_mutex_unlock(&p.locks[((p.n + 1) % p.total)]);
		printf("\n%lu %d is sleeping\n", get_time()/100 % 10000, p.n);
		if (p.time_sleep > p.time_die) // don't sleep past death
			usleep(p.time_die * 1000 + 900 * 10);
		else
			usleep(p.time_sleep * 1000);
	}
	if (p.num_eat)
		printf("\n%lu %d has died (%lu)\n", get_time()/100 % 10000, p.n, p.last_eat/100 % 10000);
	return 0; 
}

int	main(int argc, char*argv[])
{
	pthread_t pids[NUM_P];
	pthread_mutex_t locks[NUM_P];
	t_param			**param;
	int				i;

	if (argc != 5 && argc != 6)
		return (0);
	i = -1;
	param = malloc(sizeof(t_param*) * NUM_P);
	while (++i < NUM_P)
	{
		pthread_mutex_init(&(locks[i]), NULL);
		param[i] = malloc(sizeof(t_param));
		*(param[i]) = (t_param){.locks = locks, .n = i, .total = NUM_P,
		.time_eat = 200, .time_die = 500, .time_sleep = 600, .num_eat = -1};
	}
	i = -1;
	while (++i < NUM_P)
		pthread_create(&(pids[i]), NULL, &try_this, param[i]);
	i = -1;
	while (++i < NUM_P)
		pthread_join(pids[i], NULL);
	return (0);
}