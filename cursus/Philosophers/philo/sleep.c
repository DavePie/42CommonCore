/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:30:14 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/07 13:32:55 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void	ft_sleep(unsigned long to_wait)
{
	unsigned long	start;

	start = get_time();
	while (get_time() < to_wait + start)
		usleep(1000);
}
