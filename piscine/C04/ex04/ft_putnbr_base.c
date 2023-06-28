/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:42:31 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/12 18:17:42 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_in_base(long n, int b, char *base)
{
	char	ans[35];
	int		i;

	i = 0;
	if (n == 0)
		write(1, "0", 1);
	while (n > 0)
	{
		ans[i] = base[n % b];
		n /= b;
		i++;
	}
	i--;
	while (i >= 0)
		write(1, &ans[i--], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == ' ' || base[i] == '-' || base[i] == '+')
			return ;
		j = i - 1;
		while (j >= 0)
			if (base[i] == base[j--])
				return ;
		i++;
	}
	if (i < 2)
		return ;
	n = nbr;
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	write_in_base(n, i, base);
}

/*int	main(void)
{
	ft_putnbr_base(2147483647, "0123456789ABCDEF0");
	return (0);
}*/
