/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:52:29 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/10 18:02:12 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 'a' || *str > 'z'))
			return (0);
		str++;
	}
	return (1);
}
/*int main(){
	char *a = "";
	char *b = "abcd";
	char *c = "abcABCZz";
	char *d = "abd1";
	printf("%d ", ft_str_is_alpha(a));
	printf("%d ", ft_str_is_alpha(b));
	printf("%d ", ft_str_is_alpha(c));
	printf("%d ", ft_str_is_alpha(d));
}*/
