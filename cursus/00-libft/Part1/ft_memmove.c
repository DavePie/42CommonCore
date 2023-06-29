/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:55:11 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/29 09:48:19 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, long unsigned int n);

void	*ft_memmove(void *dst, const void *src, long unsigned int len)
{
	char		*to;
	const char	*from;

	if (from > to)
		return (ft_memcpy(dst, src, len));
	if (from == to)
		return (dst);
	while (len > 0)
		to[len - 1] = from[len - 1];
	return (dst);
}
