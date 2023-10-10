/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:03:46 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/09 15:10:26 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	char s[] = "tripouille";
// 	printf("%s", ft_strchr(s, 't' + 256));
// 	return 0;
// }
