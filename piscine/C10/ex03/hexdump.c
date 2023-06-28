/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:58:19 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/18 17:58:20 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "write_hex.h"
#include <libgen.h>

void	ft_print_memory(char *addr, unsigned int size, int ptr, int inc);

void	print_pointer(int z, int inc);

void	output_error(char *file, char *program);

int		get_len(char *str);

void	print_pointer_if_valid(int ptr, int itr);

int		get_size(int size, int file, char *chars);

int	get_new_file(int old, char *filename, char *program, int *found_file)
{
	if (old >= 0)
		close(old);
	old = open(filename, O_RDWR);
	if (old < 0)
		output_error(filename, program);
	else
		*found_file = 1;
	return (old);
}

int	read_file(char *chars, char **files, int num_files, int inc)
{
	int	size;
	int	ptr;
	int	file;
	int	i;
	int	found_file;

	found_file = 0;
	i = 1;
	ptr = 0;
	size = -1;
	while (size != 0)
	{
		size = get_size(size, file, chars);
		while (size < 16 && num_files-- > 0)
		{
			file = get_new_file(-1, files[i++], files[0], &found_file);
			if (file > 0)
				size += read(file, chars + size, 16 - size);
		}
		ft_print_memory(chars, size, ptr, inc);
		ptr += size;
	}
	print_pointer_if_valid(ptr, inc);
	return (found_file);
}

void	read_stdin(char *chars, int inc)
{
	int	size;
	int	ptr;
	int	temp;

	ptr = 0;
	size = read(0, chars, 16);
	while (size != 0)
	{
		temp = 1;
		while (temp != 0 && size != 16)
		{
			temp = read(0, chars + size, 16 - size);
			size += temp;
		}
		ft_print_memory(chars, size, ptr, inc);
		ptr += size;
		if (temp == 0)
			break ;
		size = read(0, chars, 16);
	}
	if (ptr > 0)
		print_pointer(ptr, inc);
	if (ptr > 0)
		write (1, "\n", 1);
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
	int		num_files;
	int		inc;

	inc = 0;
	num_files = argc - 1;
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'C' && !argv[1][2])
	{
		argv[1] = argv[0];
		argv++;
		inc = 1;
		num_files--;
	}
	if (num_files == 0)
		read_stdin(chars, inc);
	else if (!read_file(chars, argv, num_files, inc))
	{
		write(1, basename(argv[0]), get_len(basename(argv[0])));
		write(1, ": ", 2);
		write(1, argv[num_files], get_len(argv[num_files]));
		write(1, ": Bad file descriptor\n", 22);
	}
	return (0);
}
