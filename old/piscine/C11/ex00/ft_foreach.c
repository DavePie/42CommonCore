/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:11:07 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/18 22:11:17 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int));

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		f(tab[i++]);
}
/**
#include <stdio.h>
void ft_putnbr(int a)
{
	printf("%d, ", a);
}

int	main()
{
	int test[] = {1, 2, 3};
	ft_foreach(test, 3, &ft_putnbr);
	return 0;
}*/
