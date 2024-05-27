/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:34:41 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/03 17:31:00 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	mutex_print(char *s, t_param *p)
{
	sem_wait(p->write);
	if ((!(p->death) || ((p->death) == 1 && s[4] == 'd')) && p->n_eat)
	{
		printf("%lu %d %s\n", get_time() / 1000 % 1000000, p->n + 1, s);
		if ((p->death))
			(p->death) = -1;
		if (s[3] == 'e')
		{
			p->l_eat = get_time();
			p->n_eat--;
		}
	}
	if (s[4] != 'd')
		sem_post(p->write);
	return (1);
}

int	lock_mutex(t_param *p)
{
	sem_wait(p->num_f);
	if (get_time() > p->l_eat + p->t_d)
		return (0);
	mutex_print("has taken a fork", p);
	return (1);
}

int	lock_mutexes(t_param *p)
{
	if (get_time() > p->l_eat + p->t_d)
		return (0);
	if (!lock_mutex(p))
	{
		sem_post(p->num_f);
		return (0);
	}
	if (p->total == 1)
	{
		usleep(p->t_d);
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
	mutex_print("is eating", p);
	usleep(p->t_eat);
	mutex_print("is sleeping", p);
}

int	phil_process(void *param)
{
	t_param	*p;

	p = (t_param *)param;
	p->l_eat = get_time();
	while (get_time() < p->l_eat + p->t_d && !(p->death) && (p->n_eat))
	{
		mutex_print("is thinking", p);
		if (!lock_mutexes(p))
			break ;
		update_thread(p);
		sem_post(p->num_f);
		sem_post(p->num_f);
		if (p->t_slp > p->t_d)
			usleep(p->t_d + 5 * 1000);
		else
			usleep(p->t_slp);
	}
	if (!(p->death) && p->n_eat)
		(p->death) = 1;
	if (p->n_eat)
		mutex_print("has died", p);
	return (p->n_eat);
}
