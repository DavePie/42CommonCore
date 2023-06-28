/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:34:38 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/15 21:34:40 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	chars[100];
	int		size;
	int		file;

	if (argc == 1)
		write(1, "File name missing.\n", 19);
	if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	if (argc != 2)
		return (0);
	argv++;
	file = open(*argv, O_RDONLY);
	if (file < 0)
	{
		write(1, "Cannot read file.\n", 18);
		return (0);
	}
	size = read(file, chars, 100);
	while (size != 0)
	{
		write(1, chars, size);
		size = read(file, chars, 100);
	}
	close(file);
	return (0);
}
