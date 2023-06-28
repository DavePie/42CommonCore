/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperrott <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:35:05 by gperrott          #+#    #+#             */
/*   Updated: 2023/06/25 18:35:10 by gperrott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	get_len(char *input)
{
	int	i;

	i = 0;
	while (*(input++))
		i++;
	return (i);
}

int	check_for_end(char *input)
{
	while (*input == ' ')
		input++;
	if (*(input++) != ':')
		return (0);
	while (*input == ' ')
		input++;
	if (!*input || *input == '\n')
		return (0);
	return (1);
}

void	set_first_num(char **input)
{
	while (**input == ' '
		|| (**input >= 9 && **input <= 13 && **input != '\n'))
		(*input)++;
	if (**input == '+')
		(*input)++;
}

void	set_first_str(char **input)
{
	while (**input == ' ')
		(*input)++;
	if (**input == ':')
		(*input)++;
	while (**input == ' ')
		(*input)++;
}

int	contains_num(unsigned int n, int zeros, t_pair **ans)
{
	while (ans && *ans)
	{
		if ((*ans)->number == n && (*ans)->zeros == zeros)
			return (1);
		ans++;
	}
	return (0);
}
