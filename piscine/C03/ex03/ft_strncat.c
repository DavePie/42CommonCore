/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:37:22 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/11 18:56:15 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ans;

	ans = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && nb > 0)
	{
		*dest = *src;
		src++;
		dest++;
		nb --;
	}
	*dest = '\0';
	return (ans);
}

/*int main(){
	char a[10];
	a[0] = 'h';
	a[1] = 'i';
	a[2] = '\0';
	char *b = "hello";
	printf("%s", ft_strncat(a, b, 4));
}*/
