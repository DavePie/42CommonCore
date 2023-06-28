/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:11:42 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/12 16:16:46 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	print_pointer(void *addr)
{
	int				i;
	unsigned int	z;
	char			ptr[8];

	i = 7;
	z = (unsigned int) addr;
	while (i >= 0)
	{
		if (z % 16 < 10)
			ptr[i] = z % 16 + '0';
		else
			ptr[i] = z % 16 - 10 + 'a';
		i--;
		z /= 16;
	}
	write(1, "00000000", 8);
	write(1, ptr, 8);
	write(1, ": ", 2);
}

void	print_chars_from_to(unsigned char *ptr, int a, int b)
{
	while (a < b)
	{
		if (ptr[a] < ' ' || ptr[a] > '~')
			write(1, ".", 1);
		else
			write(1, &ptr[a], 1);
		a++;
	}
}

void	ft_print_memory_from_to(void *addr, int a, int b, int spaces)
{
	int				i;
	unsigned char	*p;

	p = addr;
	print_pointer(addr + a);
	i = 0;
	while (a + i < b)
	{
		write_hex((unsigned char)p[a + i]);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	if ((b - a) % 2 == 1)
		write(1, " ", 1);
	while (spaces-- > 0)
		write(1, " ", 1);
	print_chars_from_to(p, a, b);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				missing;
	unsigned char	*p;

	missing = 0;
	p = addr;
	i = 0;
	while (i < size)
	{
		missing = (16 + i - size) * 2 + (16 + i - size) / 2;
		if (i + 16 > size)
			ft_print_memory_from_to(addr, i, size, missing);
		else
			ft_print_memory_from_to(addr, i, i + 16, 0);
		i += 16;
		write(1, "\n", 1);
	}
	return (addr);
}

/*int main(){
	char y[] = "\xe8\x79\xfc\xed\xbc\x4c\x12\xce\x53\x12
	\xdc\xd5\x4d\xff\x0c\xff\x2d\xc9\xf9\xdf\xc5\x01\xc1
	\x9b\x3e\xcf\xdf\x6a\xae\x06\xaf\xee\xfb\x07\x82\xdc
	\x7f\xa5\xef\xdc\x7b\x65\xfe\xd3";
	ft_print_memory(&y, sizeof(y) - 1);
	return 0;
}*/
