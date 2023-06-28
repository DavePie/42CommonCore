/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:42:10 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/19 12:42:12 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_len(char **tab)
{
	int	l;

	l = 0;
	while (*(tab++) != 0)
		l++;
	return (l);
}

void	ft_advanced_sort_string_tab(char *vals[], int (*cmp)(char *, char *))
{
	int		i;
	int		sorted;
	char	*temp;
	int		len;

	len = get_len(vals);
	temp = 0;
	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (i < len - 1)
		{
			if (cmp(vals[i], vals[i + 1]) > 0)
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

// #include <stdio.h>
// int	is_larger(char *a, char *b)
// {
// 	while (*a != '\0' && *a == *b)
// 	{
// 		a++;
// 		b++;
// 	}
// 	return (*a - *b);
// }
// int main()
// {
// 	char *a[60] = {"a", "aa", "b", "A", "abc", "br", 0};
// 	ft_advanced_sort_string_tab(a, &is_larger);
// 	int i = 0;
// 	while (a[i])
// 	{
// 		printf("%s\n", a[i++]);
// 	}
// }
