/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:49:35 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/18 22:49:37 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
		if (f(tab[i++]))
			count++;
	return (count);
}

/*
#include <stdio.h>
int test(char *a)
{
	printf("this ran\n");
	return a[0] == 'a';
}

int main()
{
	char *a[] = {"ok", "aow", "what", "aa"};
	printf("%d", ft_count_if( a, 4, &test));
	return 0;
}*/