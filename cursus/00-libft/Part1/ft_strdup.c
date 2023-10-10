/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:41:55 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/10 13:07:46 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*start;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	start = dup;
	if (!dup)
		return (0);
	while (*s1)
		*(dup++) = *(s1++);
	*dup = '\0';
	return (start);
}
