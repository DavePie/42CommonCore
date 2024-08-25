/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:12:51 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/12 17:00:25 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	n;
	int		ans[10];
	int		i;
	char	cur;

	i = 0;
	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n == 0)
		write(1, "0", 1);
	while (n > 0)
	{
		ans[i++] = n % 10;
		n /= 10;
	}
	i--;
	while (i >= 0)
	{
		cur = ans[i--] + '0';
		write(1, &cur, 1);
	}
}

/*int	main(void)
{
	ft_putnbr(-2147483647);
	return (0);
}*/
