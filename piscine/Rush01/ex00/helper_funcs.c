/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:57:25 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/17 16:57:26 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Given two numbers, return the direction needed to reach another number
 * Ex: for 3 and 4, return 1
 * Ex: for 4 and 1, return -1
 * Ex: for 2 and 2, return 0
*/
int	get_itr(int a, int b)
{
	if (a > b)
		return (-1);
	if (a == b)
		return (0);
	return (1);
}

/**
 * Given the to_from array and the board, get the value on the board
*/
int	get_val(int *board, int *to_from_ar, int size)
{
	return (board[to_from_ar[0] * size + to_from_ar[2]]);
}

/**
 * Check from (i1, j1) to (i2, j2) for the number of visible blocks
 * *to_from_ar{ from_row, to_row, from_col, to_col}
*/
int	check_visible(int *board, int size, int *to_from_ar, int val)
{
	int	max;
	int	count;
	int	itr;
	int	row_col;

	row_col = 2 * (to_from_ar[2] != to_from_ar[3]);
	itr = get_itr(to_from_ar[0], to_from_ar[1])
		+ get_itr(to_from_ar[2], to_from_ar[3]);
	max = 0;
	count = 0;
	while (to_from_ar[row_col] != to_from_ar[row_col + 1])
	{
		if (get_val(board, to_from_ar, size) > max)
		{
			count++;
			max = get_val(board, to_from_ar, size);
		}
		to_from_ar[row_col] += itr;
	}
	return (count == val);
}

int	check_row(int *board, int *vals, int pos, int size)
{
	int	row_left[4];
	int	row_right[4];

	row_left[0] = pos / size;
	row_left[1] = pos / size;
	row_left[2] = 0;
	row_left[3] = size;
	row_right[0] = pos / size;
	row_right[1] = pos / size;
	row_right[2] = size - 1;
	row_right[3] = -1;
	return (pos % size != size - 1
		|| (check_visible(board, size, row_left, vals[size * 2 + pos / size])
			&& check_visible(board, size,
				row_right, vals[size * 3 + pos / size])));
}

int	check_col(int *board, int *vals, int pos, int size)
{
	int	col_up[4];
	int	col_down[4];

	col_up[0] = 0;
	col_up[1] = size;
	col_up[2] = pos % size;
	col_up[3] = pos % size;
	col_down[0] = size - 1;
	col_down[1] = -1;
	col_down[2] = pos % size;
	col_down[3] = pos % size;
	return ((pos < size * (size - 1)
			|| (check_visible(board, size, col_up, vals[pos % size])
				&& check_visible(board, size,
					col_down, vals[pos % size + size]))));
}
