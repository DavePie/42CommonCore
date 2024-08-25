/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:57:35 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/03 17:29:30 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_H
# define PHIL_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>

typedef struct s_param
{
	int				n;
	sem_t			*num_f;
	int				n_eat;
	unsigned long	t_slp;
	unsigned long	t_eat;
	unsigned long	t_d;
	unsigned long	l_eat;
	int				death;
	sem_t			*write;
	int				*a_eat;
	int				total;
}	t_param;
int				phil_process(void *param);
unsigned long	get_time(void);
#endif