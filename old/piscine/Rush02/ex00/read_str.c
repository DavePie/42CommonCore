/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoury <egoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 00:38:16 by egoury            #+#    #+#             */
/*   Updated: 2023/06/25 03:03:41 by egoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "rush02.h"

int		check_for_end(char *input);

void	set_first_num(char **input);

void	set_first_str(char **input);

int		contains_num(unsigned int n, int zeros, t_pair **ans);

char	*extract_str(char *input)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	while (input[i] && input[i] != '\n')
		if (input[i++] != ' ')
			len = i;
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[i] = '\0';
	len--;
	while (input[len] && input[len] != '\n' && len >= 0)
	{
		str[len] = input[len];
		len--;
	}
	return (str);
}

int	valid_line(char *input)
{
	unsigned long	num;
	unsigned int	digits_sum;
	int				length;

	num = 0;
	digits_sum = 0;
	length = 0;
	set_first_num(&input);
	if (*input < '0' || *(input--) > '9')
		return (-1);
	while (*(++input) >= '0' && *input <= '9')
	{
		digits_sum += (*(input) - '0');
		if (num < MAX_UNSIGNED_INT)
			num = num * 10 + (*(input) - '0');
		length++;
	}
	if (!check_for_end(input))
		return (-1);
	if (!(num <= 20 || (num < 100 && num % 10 == 0)
			|| (digits_sum == 1 && length <= 37)))
		return (0);
	return (length);
}

t_pair	*read_line(char *input)
{
	int		is_valid;
	t_pair	*pair;

	is_valid = valid_line(input);
	while (*input == ' ' || (*input >= 9 && *input <= 13 && *input != '\n'))
		input++;
	if (*input == '+')
		input++;
	if (is_valid == -1)
		return (0);
	pair = (t_pair *)malloc(sizeof(t_pair));
	pair->str = 0;
	pair->zeros = 0;
	if (is_valid == 0)
		return (pair);
	if (is_valid > 2)
		pair->zeros = is_valid - 1;
	pair->number = (*(input) - '0');
	if (is_valid == 2)
		pair->number = pair->number * 10 + (*(input + 1) - '0');
	input += is_valid;
	set_first_str(&input);
	pair->str = extract_str(input);
	return (pair);
}

t_pair	**dict_error(t_pair **ans, char *str)
{
	int	i;

	i = 0;
	while (ans[i])
	{
		free(ans[i]->str);
		free(ans[i++]);
	}
	free(ans);
	free(str);
	write(1, "Dict Error\n", 11);
	return (0);
}
