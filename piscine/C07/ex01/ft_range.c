/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:46:29 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/14 09:57:51 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
int	*ft_range(int min, int max)
{
	int	*ans;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	ans = (int *)malloc(sizeof(*ans) * (max - min));
	while (min < max)
		ans[i++] = min++;
	return (ans);
}

/*int	main()
{
	int* test = ft_range(10, 20);
	int i = 0;
	while (i < (20 - 10))
		printf("%d ", test[i++]);
}*/
