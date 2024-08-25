/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahanzi <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:26:11 by ahanzi            #+#    #+#             */
/*   Updated: 2023/06/10 17:37:51 by ahanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
*/

void	ft_putchar(char c);

void	put_nchar(int n, char c)
{
	while (n-- > 0)
		ft_putchar(c);
}

void	put_row(char start, char mid, char end, int x)
{
	ft_putchar(start);
	put_nchar(x - 2, mid);
	if (x > 1)
		ft_putchar(end);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = y - 2;
	if (x > 0 || y > 0)
	{
		put_row('o', '-', 'o', x);
		while (i > 0)
		{
			put_row('|', ' ', '|', x);
			i--;
		}
		if (y > 1)
			put_row('o', '-', 'o', x);
	}
}

/*
int	main(void)
{
	rush(5, 5);
	return (0);
}
*/
