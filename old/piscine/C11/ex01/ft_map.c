/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:29:43 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/18 22:29:44 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*ans;
	int	i;

	i = 0;
	ans = malloc(sizeof(*ans) * length);
	while (i < length)
	{
		ans[i] = f(tab[i]);
		i++;
	}
	return (ans);
}

// #include <stdio.h>
// int mult(int a)
// {
// 	return -a;
// }
// int main()
// {
// 	int a[] = {1, 0 , 2, 3};
// 	int *b = ft_map(a, 4, &mult);
// 	int i = 0;
// 	while (i < 4)
// 	{
// 		printf("%d, ", b[i++]);
// 	}
// 	return 0;
// }