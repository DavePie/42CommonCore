/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:48:06 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/19 10:48:08 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	increasing;
	int	cur;

	i = 1;
	increasing = 0;
	while (i < length)
	{
		cur = f(tab[i - 1], tab[i]);
		if ((cur > 0 && increasing < 0)
			|| (cur < 0 && increasing > 0))
			return (0);
		if (cur != 0)
			increasing = cur;
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int	test(int a, int b)
// {
// 	return a - b;
// }
// int main()
// {
// 	int a[] = {1, 2, 3, 3, 2};
// 	printf("%d\n", ft_is_sort(a, 5, &test));
// 	return 0;
// }
