/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:46:59 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/14 09:10:41 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_larger(char *a, char *b)
{
	while (*a != '\0' && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}

void	sort(char *vals[], int len)
{
	int		i;
	int		sorted;
	char	*temp;

	temp = 0;
	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		i = 1;
		while (i < len - 1)
		{
			if (is_larger(vals[i], vals[i + 1]) > 0)
			{
				sorted = 0;
				temp = vals[i];
				vals[i] = vals[i + 1];
				vals[i + 1] = temp;
			}
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	sort(argv, argc);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
