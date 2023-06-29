/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:41:55 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/29 13:52:39 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long unsigned int	ft_strlen(const char *s);

char	*ft_strdup(const char *s1)
{
	char	*dup;

	if (!s1)
		return (0);
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (0);
	while (*s1)
		*(dup++) = *(s1++);
	*dup = '\0';
	return (dup);
}
