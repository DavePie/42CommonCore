/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:20:45 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/16 09:20:56 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

int	get_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	read_file(int file, char *chars)
{
	int	size;

	size = read(file, chars, 30);
	while (size != 0)
	{
		write(1, chars, size);
		size = read(file, chars, 30);
	}
}

void	output_error(char *file, char *program)
{
	write(1, basename(program), get_len(basename(program)));
	write(1, ": ", 2);
	write(1, file, get_len(file));
	write(1, ": ", 2);
	write(1, strerror(errno), get_len(strerror(errno)));
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	char	chars[30];
	int		file;
	int		i;

	i = 0;
	if (--argc == 0)
		read_file(0, chars);
	while (++i <= argc)
	{
		file = open(argv[i], O_RDWR);
		if (argv[i][0] == '-' && !argv[i][1])
			read_file(0, chars);
		else if (file < 0)
			output_error(argv[i], argv[0]);
		else
			read_file(file, chars);
		close(file);
	}
	return (0);
}
