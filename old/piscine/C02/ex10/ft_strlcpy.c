/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:12:57 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/10 19:41:58 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;

	len = 0;
	if (size > 0)
	{
		while (size - 1 > 0 && *src != '\0')
		{
			*dest = *src;
			dest++;
			src++;
			len++;
			size--;
		}	
		*dest = '\0';
	}
	while (*src != '\0')
	{
		src++;
		len++;
	}
	return (len);
}
/*int main(){
	char test1[] = "Hel";
	char test2[] = "There";
	int ans = ft_strlcpy(test2, test1, 6);
	printf("%s %d", test2, ans);

}*/
