/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:20:16 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/28 19:56:43 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, long unsigned int n)
{
	char		*to;
	const char	*from;

	to = dst;
	from = src;
	while (n-- > 0)
		*(to)++ = *(from)++;
	return (dst);
}
