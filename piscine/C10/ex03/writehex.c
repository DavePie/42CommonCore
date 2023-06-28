/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writehex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:58:06 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/18 17:58:11 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	write_hex(unsigned char c)
{
	unsigned char	temp;

	if (c / 16 < 10)
		temp = c / 16 + '0';
	else
		temp = c / 16 - 10 + 'a';
	write (1, &temp, 1);
	if (c % 16 < 10)
		temp = c % 16 + '0';
	else
		temp = c % 16 - 10 + 'a';
	write(1, &temp, 1);
}

void	print_pointer(int z, int inc)
{
	int		i;
	char	ptr[8];

	i = 6 + (inc != 0);
	while (i >= 0)
	{
		if (z % 16 < 10)
			ptr[i] = z % 16 + '0';
		else
			ptr[i] = z % 16 - 10 + 'a';
		i--;
		z /= 16;
	}
	write(1, ptr, 7 + (inc != 0));
}

void	print_chars_from_to(char *ptr, int a, int b)
{
	write(1, " |", 2);
	while (a < b)
	{
		if ((unsigned char)ptr[a] < ' ' || (unsigned char)ptr[a] > '~')
			write(1, ".", 1);
		else
			write(1, &ptr[a], 1);
		a++;
	}
	write(1, "|", 1);
}

void	ft_print_memory_from_to(char *addr, int b, int spaces, int inc)
{
	int		i;

	i = 0;
	while (i < b)
	{
		write(1, " ", 1);
		write_hex((unsigned char)addr[i]);
		if (i % 8 == 7 && inc)
			write(1, " ", 1);
		i++;
	}
	while (spaces-- > 0)
		write(1, " ", 1);
}

void	ft_print_memory(char *addr, unsigned int size, int ptr, int inc)
{
	if (size == 0)
		return ;
	print_pointer(ptr, inc);
	if (inc)
		write(1, " ", 1);
	if (size == 16)
		ft_print_memory_from_to(addr, 16, 0, inc);
	else
		ft_print_memory_from_to(addr, size,
			(16 - size) * 3 + (16 - size - 1) / 8 * (inc != 0)
			+ (inc != 0), inc);
	if (inc)
		print_chars_from_to(addr, 0, size);
	write(1, "\n", 1);
}

// int	main()
// {
// 	ft_print_memory("test ok .
// Great how now why tho ok then how reeeeeeeee", 16, 32);
// 	return 0;
// }
