/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:56:11 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/08 18:04:59 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

void	write_nums(int a, int b);

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 < 99)
	{
		num2 = num1 + 1;
		while (num2 < 100)
		{
			write_nums(num1, num2);
			num2++;
		}
		num1++;
	}
}

void	write_nums(int a, int b)
{
	char	s[7];

	if (a == 98 && b == 99)
	{
		write(1, "98 99", 5);
	}
	else
	{
		s[0] = (char)(a / 10 + 48);
		s[1] = (char)(a % 10 + 48);
		s[2] = ' ';
		s[3] = (char)(b / 10 + 48);
		s[4] = (char)(b % 10 + 48);
		s[5] = ',';
		s[6] = ' ';
		write(1, s, 7);
	}
}
