/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchetela <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 23:06:54 by dchetela          #+#    #+#             */
/*   Updated: 2023/06/26 23:52:01 by dchetela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"
#include <stdlib.h>
#include <unistd.h>

int	is_printable(char c)
{
	if (32 <= c && c <= 126)
		return (1);
	else
		return (0);
}

int	ver_map(char *str, t_chars *chars, unsigned int v_nbl, unsigned int v_lgt)
{
	unsigned int	i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] == '\0')
				break ;
			if (v_lgt != chars->line_len)
				return (0);
			else
			{
				v_lgt = 0;
				v_nbl++;
				i++;
			}
		}
		if (str[i] != chars->block && str[i] != chars->empty)
			return (0);
		v_lgt++;
	}
	if (v_lgt != chars->line_len || chars->num_lines != v_nbl)
		return (0);
	return (1);
}

char	*verify_file(char *str, t_chars *chars)
{
	int				i;
	int				line_length;
	char			*start;

	i = 0;
	line_length = 0;
	while (str[i++] != '\n')
		;
	start = &str[i];
	while (str[i] != '\n' && is_printable(str[i]))
	{
		if (str[i] != chars->block && str[i] != chars->empty)
			return (0);
		line_length++;
		i++;
	}
	chars->line_len = line_length;
	if (!(str[i + 1]) && (ver_map(&str[i], chars, 1, line_length)
			&& !(line_length == 0)))
		return (start);
	else if (ver_map(&str[i], chars, 2, 0) && !(line_length == 0))
		return (start);
	return (0);
}

t_chars	*get_char_types_from_str(char *str, int i)
{
	t_chars			*p_c_types;
	unsigned int	num_lines;

	if (!(is_printable(str[0]) && is_printable(str[1]) && is_printable(str[2])))
		return (0);
	num_lines = 0;
	while (str[++i + 3] != '\n')
	{
		if (!('0' <= str[i] && str[i] <= '9') || !(is_printable(str[i + 3]))
			|| num_lines >= 429496728)
			return (0);
		num_lines = (10 * num_lines) + (str[i] - 48);
	}
	if (num_lines == 0 || str[i] == str[i + 1]
		|| str[i] == str[i + 2] || str[i + 1] == str[i + 2])
		return (0);
	p_c_types = (t_chars *)malloc(sizeof(t_chars));
	if (!p_c_types)
		return (0);
	p_c_types->num_lines = num_lines;
	p_c_types->empty = str[i++];
	p_c_types->block = str[i++];
	p_c_types->fill = str[i];
	return (p_c_types);
}
