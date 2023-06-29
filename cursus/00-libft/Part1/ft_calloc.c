/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:52:29 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/29 11:39:34 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, long unsigned int n);

void	*ft_calloc(long unsigned int count, long unsigned int size)
{
	void	*ptr;

	ptr = malloc(count * size);
	ft_bzero(ptr, size * count);
	return (ptr);
}
