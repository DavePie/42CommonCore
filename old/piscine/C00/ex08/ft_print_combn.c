/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:28:19 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/10 13:18:53 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);

void	recur_ft_print(int n, int cur, char to_print[], int print_i);

void	ft_print_combn(int n)
{
	int		num;
	char	to_print[10];

	num = 0;
	while (num < 10)
	{
		recur_ft_print(n, num, to_print, 0);
		num++;
	}
}

void	recur_ft_print(int n, int cur, char to_print[], int print_i)
{
	to_print[print_i] = (char)(cur + 48);
	if (n == 1)
	{
		if (cur != print_i)
			write(1, ", ", 2);
		write(1, to_print, print_i + 1);
	}
	else
	{
		while (cur + 1 < 10)
		{
			recur_ft_print(n - 1, cur + 1, to_print, print_i + 1);
			cur++;
		}
	}
}
