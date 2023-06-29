/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:53:58 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/29 09:48:50 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, long unsigned int n)
{
	const char	*ptr;

	ptr = s;
	while (n-- > 0)
		if (*(ptr++) == c)
			return (ptr - 1);
	return (0);
}
