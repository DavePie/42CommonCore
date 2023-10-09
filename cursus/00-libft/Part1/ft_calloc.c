/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:52:29 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/09 15:45:47 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	if ((count == 0 || size == 0) && count != SIZE_MAX)
	{
		ptr = malloc(0);
		return ptr;
	}
	if (count == SIZE_MAX || sizeof(size_t) / count < size)
		return (0);
	
	if (count < 0 || size < 0)
		return (0);
	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, size * count);
	return (ptr);
}
