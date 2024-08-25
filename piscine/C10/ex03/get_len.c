/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:36:39 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/18 21:36:42 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	print_pointer(int z, int inc);

int	get_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_pointer_if_valid(int ptr, int inc)
{
	if (ptr > 0)
		print_pointer(ptr, inc);
	if (ptr > 0)
		write (1, "\n", 1);
}

int	get_size(int size, int file, char *chars)
{
	if (size != -1 && file > 0)
		return (read(file, chars, 16));
	return (0);
}
