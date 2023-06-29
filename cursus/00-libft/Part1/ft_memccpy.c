/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:53:25 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/29 09:49:02 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, long unsigned int n)
{
	const char	*from;
	char		*to;

	from = src;
	to = dst;
	while (n-- > 0)
	{
		if (*from == c)
			return (to);
		*(to++) = *(from++);
	}
	return (0);
}
