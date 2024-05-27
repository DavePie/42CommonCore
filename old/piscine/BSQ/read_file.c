/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchetela <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:19:40 by dchetela          #+#    #+#             */
/*   Updated: 2023/06/26 22:23:24 by dchetela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	write_error(void);

void	write_ans_from_files(char **files, int num_files)
{
	int		file_index;

	file_index = 0;
	if (!files && !write_ans_from_file(0))
		write(1, "map error\n", 10);
	while (file_index < num_files)
	{
		if (!write_ans_from_file(files[file_index]))
			write(1, "map error\n", 10);
		if (num_files > 1)
			write(1, "\n", 1);
		file_index++;
	}
}

int	write_ans_from_file(char *file)
{
	char	*file_str;
	char	*arr;
	t_chars	*c_types;

	file_str = get_str_from_file(file);
	if (!file_str)
		return (0);
	c_types = get_char_types_from_str(file_str, -1);
	if (!c_types)
		free(file_str);
	if (!c_types)
		return (0);
	arr = verify_file(file_str, c_types);
	if (!arr)
	{
		free(file_str);
		free(c_types);
		return (0);
	}
	find_answer_from_arr(arr, c_types);
	free(c_types);
	free(file_str);
	return (1);
}

int	get_file(int *file, char *file_name)
{
	if (file_name)
		*file = open(file_name, O_RDWR);
	else
		*file = 0;
	return (*file >= 0);
}

char	*get_str_from_file(char *file_name)
{
	int		file;
	char	*file_chars;
	int		total_size;
	int		cur_size;

	if (!get_file(&file, file_name))
		return (0);
	file_chars = (char *)malloc(sizeof(char) * READ_SIZE);
	if (!file_chars)
		return (0);
	cur_size = read(file, file_chars, READ_SIZE);
	total_size = cur_size;
	while (cur_size != 0)
	{
		reallocate(&file_chars, total_size, total_size + READ_SIZE);
		if (!file_chars)
			return (0);
		cur_size = read(file, file_chars + total_size, READ_SIZE);
		total_size += cur_size;
	}
	if (file)
		close(file);
	file_chars[total_size] = '\0';
	return (file_chars);
}

void	reallocate(char **str, int old_size, int new_size)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (new_size));
	while (temp && i < old_size)
	{
		temp[i] = (*str)[i];
		i++;
	}
	free(*str);
	*str = temp;
}
