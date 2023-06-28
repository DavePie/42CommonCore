/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:14:33 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/16 14:27:28 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <string.h>
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	s;

	s = size;
	len = 0;
	while (*dest != '\0' && s > 0)
	{
		dest++;
		len++;
		s--;
	}
	while (*src != '\0' && s > 1)
	{
		*dest++ = *src++;
		s--;
		len++;
	}
	while (*src++ != '\0')
		len++;
	if (s > 0)
		*dest = '\0';
	return (len);
}

// int main(){
// 	char a[10] = "01234";
// 	char a1[10] = "01234";
// 	char *b = "hello";
// 	printf("%u\n", ft_strlcat(a, b, 1));
// 	printf("%s\n", a);
// 	printf("%lu\n", strlcat(a1, b, 1));
// 	printf("%s\n", a1);
// }
