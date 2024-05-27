/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperrott <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:16:54 by gperrott          #+#    #+#             */
/*   Updated: 2023/06/25 00:37:32 by egoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <unistd.h>
#include <stdlib.h>

int	get_len(char *input);

void	write_num(unsigned int n, int zeros, t_pair **ans)
{
	while (ans && *ans)
	{
		if ((*ans)->number == n && (*ans)->zeros == zeros)
		{
			write (1, (*ans)->str, get_len((*ans)->str));
			return ;
		}
		ans++;
	}
}

void	write_10_number(char *input, t_pair **dict)
{
	if (*input == '1' && *(input + 1) >= '1' && *(input + 1) <= '9')
		write_num((*input - '0') * 10 + *(input + 1) - '0', 0, dict);
	else
	{
		if (*input != '0')
			write_num((*input - '0') * 10, 0, dict);
		if (*input != '0' && *(input +1) != '0')
			write(1, "-", 1);
		if (*(input +1) != '0')
			write_num(*(input + 1) - '0', 0, dict);
	}
}

void	write_100_number(char *input, t_pair **dict, int len)
{
	if (len == 3)
	{
		if (*input != '0')
		{
			write_num(*input - '0', 0, dict);
			write(1, " ", 1);
			write_num(1, 2, dict);
			if (*(input + 1) != '0' || *(input + 2) != '0')
				write(1, " ", 1);
		}
		input++;
	}
	if (len >= 2)
	{
		write_10_number(input, dict);
	}
	if (len == 1 && *input != '0')
		write_num(*input - '0', 0, dict);
}

void	write_100_group(char *input, t_pair **dict, int len)
{
	if (input[0] != '0' || input[1] != '0' || input[2] != '0')
	{
		write(1, " ", 1);
		write_100_number(input, dict, 3);
		if (len > 0)
			write(1, " ", 1);
		if (len > 2)
			write_num(1, len, dict);
	}
}

void	write_number(char *input, t_pair **dict, int len)
{
	int	cur;
	int	i;

	i = 0;
	cur = len % 3;
	if (cur == 0)
		cur = 3;
	if (len == 1 && input[0] == '0')
		write_num(0, 0, dict);
	write_100_number(input, dict, cur);
	write(1, " ", 1);
	len -= cur;
	if (len > 2)
		write_num(1, len, dict);
	input += cur;
	while (len > 0)
	{
		len -= 3;
		write_100_group(input, dict, len);
		input += 3;
	}
	write(1, "\n", 1);
}
