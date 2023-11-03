/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:34:41 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/03 11:05:18 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	mutex_print(char *s, unsigned long time, t_param *p)
{
	sem_wait(p->write);
	if (!(p->death) || ((p->death) == 1 && s[4] == 'd'))
	{
		printf("%lu %d %s\n", time / 1000 % 1000000, p->n + 1, s);
		if ((p->death))
			(p->death) = -1;
	}
	if (s[4] != 'd')
		sem_post(p->write);
	return (1);
}

int	lock_mutex(t_param *p)
{
	sem_wait(p->num_f);
	if (get_time() > p->last_eat + p->t_die)
		return (0);
	mutex_print("has taken a fork", get_time(), p);
	return (1);
}

int	lock_mutexes(t_param *p)
{
	if (get_time() > p->last_eat + p->t_die)
		return (0);
	if (!lock_mutex(p))
	{
		sem_post(p->num_f);
		return (0);
	}
	if (!lock_mutex(p))
	{
		sem_post(p->num_f);
		sem_post(p->num_f);
		return (0);
	}
	return (1);
}

void	update_thread(t_param *p)
{
	mutex_print("is eating", get_time(), p);
	usleep(p->t_eat);
	p->last_eat = get_time();
	p->n_eat--;
	mutex_print("is sleeping", get_time(), p);
}

int	phil_process(void *param)
{
	t_param	*p;

	p = (t_param *)param;
	p->last_eat = get_time();
	while (get_time() < p->last_eat + p->t_die && !(p->death) && (p->n_eat))
	{
		mutex_print("is thinking", get_time(), p);
		if (!lock_mutexes(p))
			break ;
		update_thread(p);
		sem_post(p->num_f);
		sem_post(p->num_f);
		if (p->t_slp > p->t_die)
			usleep(p->t_die + 5 * 1000);
		else
			usleep(p->t_slp);
	}
	if (!(p->death) && p->n_eat)
		(p->death) = 1;
	if (p->n_eat)
		mutex_print("has died", get_time(), p);
	return (p->n_eat);
}
