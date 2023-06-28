/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:10:26 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/12 20:19:43 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_iterative_factorial(int nb)
{
	int	ans;

	if (nb < 0)
		return (0);
	ans = 1;
	while (nb > 1)
		ans *= nb--;
	return (ans);
}

/*int main(void)
{
	printf("%d\n", ft_iterative_factorial(6));
	return 0;
}*/
