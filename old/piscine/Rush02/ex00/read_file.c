/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoury <egoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:20:30 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/25 21:03:32 by egoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "rush02.h"
#include <fcntl.h>

void	reallocate(char **from, int cur_size, int new_size)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (new_size));
	while (i < cur_size)
	{
		temp[i] = (*from)[i];
		i++;
	}
	free(*from);
	*from = temp;
}

int	get_count(char *str)
{
	int		count;
	char	prev;

	prev = '\n';
	count = 0;
	while (*str)
	{
		if (prev == '\n' && *str != '\n')
			count++;
		prev = *(str++);
	}
	return (count);
}

int	add_line_to_arr(char *str, int i, int *j, t_pair **ans)
{
	t_pair	*p;

	p = read_line(str + i);
	if (!p)
		return (0);
	if (p->str == 0)
		free(p);
	else if (contains_num(p->number, p->zeros, ans))
	{
		free(p);
		return (0);
	}
	else
		ans[(*j)++] = p;
	return (1);
}

t_pair	**read_str(char *str)
{
	int		i;
	t_pair	**ans;
	int		j;

	j = 0;
	if (!*str)
		return (0);
	ans = (t_pair **)malloc(sizeof(t_pair *) * (INITIAL_SIZE + 1));
	i = 0;
	while (i < INITIAL_SIZE + 1)
		ans[i++] = 0;
	i = 0;
	if (str[i] && str[i] != '\n' && !add_line_to_arr(str, i, &j, ans))
		return (dict_error(ans, str));
	while (str[++i])
		if (str[i - 1] == '\n' && str[i] != '\n'
			&& !add_line_to_arr(str, i, &j, ans))
			return (dict_error(ans, str));
	ans[j] = 0;
	if (str[i - 1] != '\n')
		return (dict_error(ans, str));
	free(str);
	return (ans);
}

t_pair	**read_file(char *file_name)
{
	int		file;
	char	*file_chars;
	int		total_size;
	int		cur_size;

	total_size = READ_SIZE;
	file = open(file_name, O_RDWR);
	if (file <= 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	file_chars = (char *)malloc(sizeof(char) * total_size);
	cur_size = read(file, file_chars, READ_SIZE);
	while (cur_size == READ_SIZE)
	{
		reallocate(&file_chars, total_size, total_size + READ_SIZE);
		cur_size = read(file, file_chars + total_size, READ_SIZE);
		total_size += READ_SIZE;
	}
	close(file);
	file_chars[total_size - READ_SIZE + cur_size] = '\0';
	return (read_str(file_chars));
}
