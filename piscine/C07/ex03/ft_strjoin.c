/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:20:04 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/16 12:34:39 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
//#include<stdio.h>
int	get_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	ans;

	if (size <= 0)
		return (1);
	ans = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		ans += j;
		i++;
	}
	i = 0;
	while (sep[i])
		i++;
	ans += (size - 1) * i;
	return (ans + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ans;
	int		total_size;
	int		i;
	int		j;
	int		k;

	ans = "";
	total_size = get_len(size, strs, sep);
	ans = (char *)malloc(sizeof(ans) * total_size);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			ans[k++] = strs[i][j++];
		j = 0;
		while (i != size - 1 && sep[j])
			ans[k++] = sep[j++];
		i++;
	}
	ans[k] = '\0';
	return (ans);
}

int	main(void)
{
	char *c[10] = {"a", "", "hahah", "ok", ""};
	char **input = c;
	char* sep = "<sep>";
	char* ans = ft_strjoin(4, input, sep);
	printf("%s\n", ans);
	int i = 0;
	while (ans[i]){
		i++;
	}
	if (ans[i] == '\0')
		i++;
	printf("Actual size: %d ", i);
	return 0;
}
