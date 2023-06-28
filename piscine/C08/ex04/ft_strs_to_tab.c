/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:24:24 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/15 13:12:05 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"
//#include <stdio.h>
//#include <unistd.h>
char	*copy_string(char *str, int *size)
{
	int		j;
	char	*ans;

	j = 0;
	while (str[j])
		j++;
	ans = (char *)malloc(sizeof(*ans) * (j + 1));
	j = 0;
	while (str[j])
	{
		ans[j] = str[j];
		j++;
	}
	*size = j;
	ans[j] = '\0';
	return (ans);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ans;
	int			i;
	int			j;

	i = 0;
	ans = (struct s_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (ans == 0)
		return (0);
	while (i < ac)
	{
		j = 0;
		ans[i].str = av[i];
		ans[i].copy = copy_string(av[i], &ans[i].size);
		i++;
	}
	ans[i].str = 0;
	return (ans);
}

/*void	write_string(char *a)
{
	while (*a)
		write(1, a++, 1);
	write(1, "\n", 1);
}

void	write_size(int a)
{
	char	to_write;

	if (a != 0)
	{
		write_size(a / 10);
		to_write = a % 10 + '0';
		write(1, &to_write, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str != 0)
	{
		write_string((*par).str);
		if ((*par).size == 0)
			write(1, "0", 1);
		write_size((*par).size);
		write(1, "\n", 1);
		write_string((*par).copy);
		par++;
	}
}
int	main(void)
{
	char *b[] = {"", "there", "my", "best", "bud"};
	struct s_stock_str *ans = ft_strs_to_tab(0, b);
	int i = 0;
	while (ans[i].str != 0){
		printf("str: <%s> copy: <%s> size: <%d>\n",
	   	ans[i].str, ans[i].copy, ans[i].size);
		i++;
	}
	ft_show_tab(ans);
	return 0;
}*/
