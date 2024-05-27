/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchetela <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:24:05 by dchetela          #+#    #+#             */
/*   Updated: 2023/06/26 23:08:13 by dchetela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"
#include <stdlib.h>
#include <unistd.h>

void	write_square_at(char *arr, int pos, int size, t_chars *c_types)
{
	int	i;
	int	len;

	len = c_types->line_len + 1;
	i = -1;
	while (arr[++i])
	{
		if (i % len >= pos % len && i % len < pos % len + size
			&& i / len >= pos / len && i / len < pos / len + size)
			write(1, &(c_types->fill), 1);
		else
			write(1, &(arr[i]), 1);
	}
}

int	largest_square_at(char *arr, int pos, t_chars *c_types)
{
	unsigned int	size;
	unsigned int	x_len;
	unsigned int	i;

	x_len = c_types->line_len + 1;
	size = 0;
	while (pos % x_len + size < c_types->line_len
		&& pos / x_len + size < c_types->num_lines)
	{
		i = -1;
		while (++i <= size)
		{
			if (arr[i * x_len + pos + size] == c_types->block
				|| arr[size * x_len + pos + i] == c_types->block)
				return (size);
		}
		size++;
	}
	return (size);
}

void	find_answer_from_arr(char *arr, t_chars *c_types)
{
	int				max_size;
	int				max_pos;
	unsigned int	i;
	int				cur_size;

	i = 0;
	max_size = 0;
	max_pos = 0;
	while (i < (c_types->line_len + 1) * c_types->num_lines)
	{
		cur_size = largest_square_at(arr, i, c_types);
		if (cur_size > max_size)
		{
			max_pos = i;
			max_size = cur_size;
		}
		i++;
	}
	write_square_at(arr, max_pos, max_size, c_types);
}
