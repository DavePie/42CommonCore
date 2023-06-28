/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:54:25 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/13 16:22:50 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//#include <stdio.h>
int	can_place_queen(int i, int j, int board[100])
{
	int	k;

	k = i;
	while (k >= 0)
	{
		if (board[k * 10 + j] == 1)
			return (0);
		k--;
	}
	k = 1;
	while (i - k >= 0)
	{
		if ((j - k >= 0 && board[(i - k) * 10 + j - k] == 1)
			|| (j + k < 10 && board[(i - k) * 10 + j + k] == 1))
			return (0);
		k++;
	}
	return (1);
}

void	write_char(char c)
{
	write(1, &c, 1);
}

void	write_board(int board[100])
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (board[i * 10 + j] == 1)
				write_char('0' + j);
			j++;
		}
		i++;
	}
	write_char('\n');
}

int	check_queen(int row, int board[100])
{
	int	j;
	int	total;

	total = 0;
	if (row == 10)
	{
		write_board(board);
		return (1);
	}
	j = 0;
	while (j < 10)
	{
		if (can_place_queen(row, j, board) == 1)
		{
			board[row * 10 + j] = 1;
			total += check_queen(row + 1, board);
			board[row * 10 + j] = 0;
		}
		j++;
	}
	return (total);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[100];
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i * 10 + j] = 0;
			j++;
		}
		i++;
	}
	return (check_queen(0, board));
}

/*int main(void)
{
	printf("%d\n", ft_ten_queens_puzzle());
	return (0);
}*/
