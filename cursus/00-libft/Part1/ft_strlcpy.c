/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:12:57 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/29 13:53:04 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long unsigned int	ft_strlcpy(char *dest, char *src, long unsigned int size)
{
	unsigned int	len;

	len = 0;
	while (--size > 0 && *src != '\0')
	{
		*dest++ = *src++;
		len++;
	}
	if (size > 0)
		*dest = '\0';
	while (*src != '\0')
	{
		src++;
		len++;
	}
	return (len);
}
