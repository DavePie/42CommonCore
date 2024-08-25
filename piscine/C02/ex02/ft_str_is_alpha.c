/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:33:03 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/10 14:45:58 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z'))
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
