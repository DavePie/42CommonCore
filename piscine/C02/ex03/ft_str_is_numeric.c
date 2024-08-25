/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:47:28 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/10 14:50:15 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if ((*str < '0' || *str > '9'))
			return (0);
		str++;
	}
	return (1);
}
/*int main(){
	char *a = "";
	char *b = "0123";
	char *c = "d1203";
	char *d = "9999999999";
	printf("%d ", ft_str_is_numeric(a));
	printf("%d ", ft_str_is_numeric(b));
	printf("%d ", ft_str_is_numeric(c));
	printf("%d ", ft_str_is_numeric(d));
}*/
