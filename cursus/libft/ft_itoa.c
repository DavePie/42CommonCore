/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:27:39 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/11 17:59:32 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	temp;
	int		len;
	char	*s;

	temp = n;
	len = 1;
	while (temp != 0 && len++)
		temp /= 10;
	temp = n;
	if (n <= 0 && len++)
		temp *= -1;
	s = malloc(sizeof(char) * (len));
	if (!s)
		return (0);
	s[--len] = '\0';
	while ((len >= 0 && n >= 0) || len > 0)
	{
		s[--len] = (char)(temp % 10 + '0');
		temp /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
