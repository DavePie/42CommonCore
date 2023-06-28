/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:01:28 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/17 21:01:30 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>

int	get_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	fix_tail(char	*tail, int t)
{
	int	i;
	int	j;

	i = 0;
	j = t;
	while (j < 3 * t)
		tail[i++] = tail[j++];
}

void	get_start_index(int file, int tail)
{
	int		total;
	int		actualtotal;
	int		size;
	char	*curinput;

	curinput = (char *)malloc(sizeof(char) * tail * 3);
	total = 0;
	actualtotal = 0;
	size = read(file, curinput, tail);
	while (size != 0)
	{
		actualtotal += size;
		total += size;
		if (total >= tail * 2)
		{
			fix_tail(curinput, tail);
			total -= tail;
		}
		size = read(file, curinput + total, tail);
	}
	if (actualtotal < tail)
		write(1, curinput, actualtotal);
	else
		write(1, curinput + total - tail, tail);
	free(curinput);
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

void	set_up(char *name, int tail, char *chars, int std)
{
	int	file;

	chars = 0;
	file = open(name, O_RDWR);
	if (std)
	{
		close(file);
		file = 0;
	}
	get_start_index(file, tail);
}
