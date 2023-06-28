/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:57:22 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/21 18:38:22 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

void	set_up(char *name, int tail, char *chars, int std);

int		get_len(char *str);

void	output_error(char *file, char *program);

int	atoi(char *c, char *program)
{
	int		ans;
	char	*p;

	p = c;
	ans = 0;
	while (*c)
	{
		if (*c >= '0' && *c <= '9')
			ans = ans * 10 + *(c++) - '0';
		else
		{
			write(1, basename(program), get_len(basename(program)));
			write(1, ": illegal offset -- ", 20);
			write(1, p, get_len(p));
			write(1, "\n", 1);
			return (-1);
		}
	}
	return (ans);
}

void	write_sep(int argc, char *name)
{
	if (argc > 4)
	{
		write(1, "==> ", 4);
		write(1, name, get_len(name));
		write(1, " <==\n", 5);
	}
}

void	write_all(char **argv, int argc, int tail, char *chars)
{
	int	i;
	int	file;
	int	prev;

	prev = 0;
	i = 2;
	while (++i < argc)
	{
		file = open(argv[i], O_RDWR);
		if (file < 0)
			output_error(argv[i], argv[0]);
		else
		{
			if (prev)
				write(1, "\n", 1);
			close(file);
			write_sep(argc, argv[i]);
			set_up(argv[i], tail, chars, 0);
		}
		prev = (prev || file > 0);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		tail;
	char	chars[30];

	i = 2;
	tail = 0;
	if (argc < 3)
	{
		write(1, basename(argv[0]), get_len(basename(argv[0])));
		write(1, ": option requires an argument -- c\n", 39);
		write(1, "usage: tail [-F | -f | -r] [-q]", 31);
		write(1, " [-b # | -c # | -n #] [file ...]\n", 33);
		return (0);
	}
	tail = atoi(argv[i], argv[0]);
	if (tail < 0)
		return (0);
	if (argc == 3)
		set_up("", tail, chars, 1);
	write_all(argv, argc, tail, chars);
	return (0);
}
