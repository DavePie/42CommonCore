/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:13:49 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/31 14:16:09 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_H
# define PHIL_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h> 
# include <sys/time.h>
# define NUM_P 7

typedef struct s_param
{
	pthread_mutex_t	*locks;
	int				n;
	int				total;
	int				num_eat;
	unsigned long	time_sleep;
	unsigned long	time_eat;
	unsigned long	time_die;
	unsigned long	last_eat;
}	t_param;
#endif