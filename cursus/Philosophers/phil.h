/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:13:49 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/31 17:24:40 by dvandenb         ###   ########.fr       */
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
}	t_param;
#endif