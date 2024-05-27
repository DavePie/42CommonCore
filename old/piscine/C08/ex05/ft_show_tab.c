/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:41:30 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/17 19:52:52 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	write_string(char *a)
{
	while (*a)
		write(1, a++, 1);
	write(1, "\n", 1);
}

void	write_size(int a)
{
	char	to_write;

	if (a != 0)
	{
		write_size(a / 10);
		to_write = a % 10 + '0';
		write(1, &to_write, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str != 0)
	{
		write_string((*par).str);
		if ((*par).size == 0)
			write(1, "0", 1);
		write_size((*par).size);
		write(1, "\n", 1);
		write_string((*par).copy);
		par++;
	}
}
