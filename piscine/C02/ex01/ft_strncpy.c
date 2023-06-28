/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:47:28 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/12 16:34:00 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <string.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*top;

	top = dest;
	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (top);
}
/*int main() {
  char str1[20] = "C programming";
  char str2[20] = "aaaaaaaaaaaaaaaaaaaa";
    char str3[20] = "aaaaaaaaaaaaaaaaaaaa";
  // copying str1 to str2
  stpncpy(str2, str1,17);
  stpncpy(str3, str1,18);
    write(1, str2, 20);
    write(1, "\n",1);
    write(1, str3, 20);

  return 0;
}*/
