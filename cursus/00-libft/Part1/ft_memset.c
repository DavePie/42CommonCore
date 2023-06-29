/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:24:36 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/28 18:14:10 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *add, int c, long unsigned int len)
{
	unsigned char	*ptr;

	if (!add)
		return (add);
	ptr = (unsigned char *)add;
	while (len-- > 0)
		*(ptr++) = (unsigned char)c;
	return (add);
}
