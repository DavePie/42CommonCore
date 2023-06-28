/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:03:52 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/14 19:52:15 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
int	in_charset(char *charset, char a)
{
	while (*charset)
		if (a == *(charset++))
			return (1);
	return (0);
}

int	count_strs(char *str, char *charset)
{
	int	prev_char;
	int	cur_char;
	int	total;

	total = 0;
	prev_char = 1;
	while (*str)
	{
		cur_char = in_charset(charset, *str++);
		if (!cur_char && prev_char)
			total++;
		prev_char = cur_char;
	}
	return (total);
}

char	*get_word(char *str, char *charset, int *j)
{
	int		i;
	char	*ans;

	i = 0;
	while (str[i] && !in_charset(charset, str[i]))
		i++;
	ans = (char *)malloc(sizeof(*ans) * (i + 1));
	*j = i;
	ans[i] = '\0';
	while (--i >= 0)
		ans[i] = str[i];
	return (ans);
}

char	**ft_split(char *str, char *charset)
{
	int		total;
	char	**ans;
	int		i;
	int		j;

	i = 0;
	total = count_strs(str, charset);
	ans = (char **)malloc(sizeof(*ans) * (total + 1));
	while (*str)
	{
		j = 1;
		if (!in_charset(charset, *str))
			ans[i++] = get_word(str, charset, &j);
		str += j;
	}
	ans[i] = 0;
	return (ans);
}
/*int main(){
	char ** test = ft_split("abcd", "aaaaaa");
	while (*test != 0){
		printf("<%s> ", *test);
		test++;
	}
	printf("\n");
	char ** test2 = ft_split("", "");
	while (*test2 != 0)
	{
		printf("uh oh");
		test2++;
	}
	return (0);
}*/
