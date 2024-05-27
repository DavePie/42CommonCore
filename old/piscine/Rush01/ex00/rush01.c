/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:57:55 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/16 19:57:57 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	check_col(int *board, int *vals, int pos, int size);

int	check_row(int *board, int *vals, int pos, int size);

/**
 * Returns true (1) or false (0) if a number was already used in
 * a row or column
*/
int	check_repeat(int *board, int pos, int size)
{
	int	i;
	int	j;

	i = pos / size;
	j = pos % size;
	while (--i >= 0)
		if (board[pos] == board[i * size + j])
			return (0);
	i = pos / size;
	while (--j >= 0)
		if (board[pos] == board[i * size + j])
			return (0);
	return (1);
}

/**
 * Print the board
*/
void	print_board(int *board, int size)
{
	int		i;
	char	c;

	i = 0;
	while (i < size * size)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		if (i % size == size - 1)
			write(1, "\n", 1);
		i++;
	}
}

/**
 * Given a starting row and column, check if you see the correct
 * number of rectangles
*/
int	check_board(int *board, int *vals, int pos, int size)
{
	int	val;

	if (pos == size * size)
	{
		print_board(board, size);
		return (1);
	}
	val = 1;
	while (val <= size)
	{
		board[pos] = val;
		if (check_repeat(board, pos, size)
			&& (check_row(board, vals, pos, size))
			&& (check_col(board, vals, pos, size)))
		{
			if (check_board(board, vals, pos + 1, size))
				return (1);
		}
		board[pos] = 0;
		val++;
	}
	return (0);
}

int	get_size(int argc, char **argv, int *vals)
{
	int	i;

	if (argc != 2)
		return (0);
	i = 0;
	while (*argv[1] && i < 38)
	{
		if (*argv[1] < '0' || *argv[1] > '9')
			return (0);
		vals[i++] = *(argv[1]++) - '0';
		if (*argv[1])
			if (*argv[1]++ != ' ')
				return (0);
	}
	if (i % 4 != 0)
		return (0);
	return (i / 4);
}

/**
 * Main entry point, verifies input
*/
int	main(int argc, char **argv)
{
	int		vals[38];
	int		board[81];
	int		i;
	int		size;

	size = get_size(argc, argv, vals);
	if (size == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = -1;
	while (++i < 81)
		board[i] = 0;
	if (!check_board(board, vals, 0, size))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}
