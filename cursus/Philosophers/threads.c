/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:34:41 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/01 16:43:47 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	mutex_print(char *s, unsigned long time, t_param *p)
{
	pthread_mutex_lock((p->write));
	if (!*(p->death) || (*(p->death) == 1 && s[4] == 'd'))
	{
		printf("%lu %d %s\n", time, p->n + 1, s);
		if (*(p->death))
			*(p->death) = -1;
	}
	pthread_mutex_unlock((p->write));
	return (1);
}

int	lock_mutex(pthread_mutex_t *left, pthread_mutex_t *right,
	t_param *p)
{
	if (p->n % 2)
		pthread_mutex_lock(left);
	else
		pthread_mutex_lock(right);
	if (get_time() > p->last_eat + p->t_die)
		return (0);
	mutex_print("has taken a fork", get_time(), p);
	return (1);
}

int	lock_mutexes(pthread_mutex_t *left, pthread_mutex_t *right,
	t_param *p)
{
	if (get_time() > p->last_eat + p->t_die)
		return (0);
	if (!lock_mutex(left, right, p))
	{
		if (p->n % 2)
			pthread_mutex_unlock(left);
		else
			pthread_mutex_unlock(right);
		return (0);
	}
	if (!lock_mutex(right, left, p))
	{
		pthread_mutex_unlock(left);
		pthread_mutex_unlock(right);
		return (0);
	}
	return (1);
}

void	update_thread(t_param *p)
{
	mutex_print("is eating", get_time(), p);
	usleep(p->t_eat * 1000);
	p->last_eat = get_time();
	p->n_eat--;
	mutex_print("is sleeping", get_time(), p);
}

void	*phil_thread(void *param)
{
	t_param	*p;

	p = (t_param *)param;
	p->last_eat = get_time();
	while (get_time() < p->last_eat + p->t_die && !*(p->death) && (p->n_eat))
	{
		mutex_print("is thinking", get_time(), p);
		if (!lock_mutexes(&p->ls[p->n], &p->ls[((p->n + 1) % p->total)], p))
			break ;
		update_thread(p);
		pthread_mutex_unlock(&p->ls[p->n]);
		pthread_mutex_unlock(&p->ls[((p->n + 1) % p->total)]);
		if (p->t_slp > p->t_die)
			usleep(p->t_die * 1000 + 5 * 1000);
		else
			usleep(p->t_slp * 1000);
	}
	if (!*(p->death) && p->n_eat)
		*(p->death) = 1;
	if (p->n_eat)
		mutex_print("has died", get_time(), p);
	return (0);
}
