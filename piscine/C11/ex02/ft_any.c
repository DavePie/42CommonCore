/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:41:57 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/18 22:41:59 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	while (*tab)
		if (f(*(tab++)))
			return (1);
	return (0);
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
	char *a[] = {"ok", "aow", "what", 0};
	printf("%d", ft_any( a, &test));
	return 0;
}*/