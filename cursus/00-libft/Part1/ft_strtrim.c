/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:10 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/09 17:12:20 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	int		slen;
	int		i;

	while (s1 && *s1 && ft_strchr(set, *s1))
		s1++;
	slen = 0;
	while (s1[slen] && !ft_strchr(set, s1[slen]))
		slen++;
	i = -1;
	ans = malloc(sizeof(char) * (slen - 1) + 1);
	while (++i < slen)
		ans[i] = s1[i];
	ans[i] = '\0';
	return (ans);
}
