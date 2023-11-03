/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:34:41 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/03 16:44:59 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	mutex_print(char *s, t_param *p)
{
	pthread_mutex_lock((p->write));
	if ((!*(p->d) && s[4] == 'd'))
		*(p->d) = 1;
	if ((!*(p->d) || (*(p->d) == 1 && s[4] == 'd')) && *(p->a_eat) < p->tot)
	{
		if (p->n_eat == 1 && s[3] == 'e')
			(*(p->a_eat))++;
		printf("%lu %d %s\n", get_time() / 1000 % 1000000, p->n + 1, s);
		if (*(p->d))
			*(p->d) = -1;
	}
	pthread_mutex_unlock((p->write));
	return (1);
}

int	lock_mutex(pthread_mutex_t *left, t_param *p)
{
	pthread_mutex_lock(left);
	if (get_time() > p->l_eat + p->t_d)
		return (0);
	mutex_print("has taken a fork", p);
	return (1);
}

int	lock_mutexes(pthread_mutex_t *left, pthread_mutex_t *right,
	t_param *p)
{
	if (p->n % 2 && p->t_eat >= p->t_d)
		usleep(p->t_d + 1000);
	if (get_time() > p->l_eat + p->t_d)
		return (0);
	if (!lock_mutex(left, p))
	{
		pthread_mutex_unlock(left);
		return (0);
	}
	if (p->tot == 1)
	{
		usleep(p->t_d);
		return (0);
	}
	if (!lock_mutex(right, p))
	{
		pthread_mutex_unlock(left);
		pthread_mutex_unlock(right);
		return (0);
	}
	return (1);
}

void	update_thread(t_param *p)
{
	mutex_print("is eating", p);
	p->l_eat = get_time();
	usleep(p->t_eat);
	if (p->n_eat > 0)
		p->n_eat--;
	mutex_print("is sleeping", p);
}

void	*phil_thread(void *param)
{
	t_param	*p;

	p = (t_param *)param;
	p->l_eat = get_time();
	if (p->n % 2)
		usleep(15000);
	while (get_time() < p->l_eat + p->t_d && !*(p->d) && (*(p->a_eat) < p->tot))
	{
		mutex_print("is thinking", p);
		if (!lock_mutexes(&p->ls[p->n], &p->ls[((p->n + 1) % p->tot)], p))
			break ;
		update_thread(p);
		pthread_mutex_unlock(&p->ls[p->n]);
		pthread_mutex_unlock(&p->ls[((p->n + 1) % p->tot)]);
		if (p->t_slp > p->t_d)
			usleep(p->t_d + 5 * 1000);
		else
			usleep(p->t_slp);
	}
	if (p->n_eat)
		mutex_print("has died", p);
	return (0);
}
