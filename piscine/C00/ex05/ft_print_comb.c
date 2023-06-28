/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:38:19 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/08 18:02:13 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	write_nums(int a, int b, int c);

void	ft_print_comb(void)
{
	int		num1;
	int		num2;
	int		num3;

	num1 = 0;
	while (num1 < 8)
	{
		num2 = num1 + 1;
		while (num2 < 9)
		{
			num3 = num2 + 1;
			while (num3 < 10)
			{
				write_nums(num1, num2, num3);
				num3++;
			}
			num2++;
		}
		num1++;
	}
}

void	write_nums(int a, int b, int c)
{
	char	s[4];

	if (a == 7 && b == 8 && c == 9)
	{
		write(1, "789", 3);
	}
	else
	{
		s[0] = (char)(a + 48);
		s[1] = (char)(b + 48);
		s[2] = (char)(c + 48);
		write(1, s, 3);
		write(1, ", ", 2);
	}
}
