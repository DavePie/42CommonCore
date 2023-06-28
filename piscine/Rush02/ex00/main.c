/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoury <egoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:26:03 by egoury            #+#    #+#             */
/*   Updated: 2023/06/25 03:05:54 by egoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush02.h"
#include <stdlib.h>

int	valid_arg(char *input, char **output)
{
	int		length;
	char	*first_number;

	first_number = 0;
	length = 0;
	while (*input == ' ' || (*input >= 9 && *input <= 13))
		(input)++;
	if (*input == '+')
		(input)++;
	if (*input < '0' || *(input) > '9')
		return (0);
	while (*input == '0' && *(input + 1) >= '0' && *(input + 1) <= '9')
		input++;
	first_number = input;
	input--;
	while (*(++input) >= '0' && *input <= '9')
		length++;
	if (!(length <= 39))
		return (0);
	*output = first_number;
	return (input - first_number);
}

void	free_pairs(t_pair **dict)
{
	int	i;

	i = 0;
	while (dict[i])
	{
		free(dict[i]->str);
		free(dict[i++]);
	}
	free(dict);
}

int	main(int argc, char **argv)
{
	t_pair	**ans;
	int		len;

	if (argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	len = valid_arg(argv[argc - 1], &(argv[argc - 1]));
	if (!len)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
		ans = read_file("numbers.dict");
	else
		ans = read_file(argv[1]);
	if (ans)
		write_number(argv[argc - 1], ans, len);
	if (ans)
		free_pairs(ans);
	return (0);
}
