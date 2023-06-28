/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:22:16 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/13 10:23:22 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int a);

int	ft_strncmp(char *s1, char *s2, unsigned int a)
{
	while (*s1 != '\0' && *s1 == *s2 && a > 0)
	{
		s1++;
		s2++;
		a--;
	}
	if (a == 0)
		return (0);
	return (*s1 - *s2);
}
/*int main()
{
	char *a = "hello";
	char *b = "helloo";
	printf("%d", ft_strncmp(a, b, 5));
	return 0;
}*/
