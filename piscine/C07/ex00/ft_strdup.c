/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:28:45 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/18 11:44:48 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *src)
{
	int		l;
	char	*str;

	l = 0;
	while (src[l])
		l++;
	str = (char *)malloc(sizeof(*str) * l);
	if (str == 0)
		return (0);
	l = 0;
	while (src[l])
	{
		str[l] = src[l];
		l++;
	}
	str[l] = '\0';
	return (str);
}

/*int main()
{
	char *a = "lkjsdflkjsdflkdsj";
	char *b = ft_strdup(a);
	printf("%s\n", b);
}*/
