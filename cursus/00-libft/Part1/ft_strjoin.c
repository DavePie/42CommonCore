/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:36:17 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/09 16:58:19 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*ans;
	size_t	i;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (sizeof(size_t) - s1len <= s2len)
		return (0);
	ans = malloc(s1len + s2len + 1);
	i = -1;
	while (++i < s1len)
		ans[i] = s1[i];
	i = -1;
	while (++i < s2len)
		ans[i + s1len] = s2[i];
	ans[i + s1len] = '\0';
	return (ans);
}
