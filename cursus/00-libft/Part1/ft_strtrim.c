/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:10 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/10 13:58:02 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *s);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	int		slen;
	int		i;

	while (s1 && *s1 && ft_strchr(set, *s1))
		s1++;
	slen = ft_strlen(s1);
	while (slen - 1 >= 0 && s1[slen - 1] && ft_strchr(set, s1[slen - 1]))
		slen--;
	i = -1;
	ans = malloc(sizeof(char) * (slen) + 1);
	if (!ans)
		return (0);
	while (++i < slen)
		ans[i] = s1[i];
	ans[i] = '\0';
	return (ans);
}
