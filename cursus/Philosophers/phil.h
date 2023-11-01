/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:13:49 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/01 16:43:43 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_H
# define PHIL_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h> 
# include <sys/time.h>

typedef struct s_param
{
	pthread_mutex_t	*ls;
	int				n;
	int				total;
	int				n_eat;
	unsigned long	t_slp;
	unsigned long	t_eat;
	unsigned long	t_die;
	unsigned long	last_eat;
	int				*death;
	pthread_mutex_t	*write;
}	t_param;
void			*phil_thread(void *param);
unsigned long	get_time(void);

#endif