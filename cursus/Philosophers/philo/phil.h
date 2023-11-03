/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:13:49 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/03 14:45:09 by dvandenb         ###   ########.fr       */
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
	int				tot;
	int				n_eat;
	int				*a_eat;
	unsigned long	t_slp;
	unsigned long	t_eat;
	unsigned long	t_d;
	unsigned long	l_eat;
	int				*d;
	pthread_mutex_t	*write;
}	t_param;
void			*phil_thread(void *param);
unsigned long	get_time(void);

#endif