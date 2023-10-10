/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:58:07 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/09 16:45:28 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);

char	*ft_substr(char const *s, unsigned int start,
size_t len)
{
	size_t	curlen;
	char	*substr;
	size_t	i;

	curlen = ft_strlen(s);
	if (start >= curlen || curlen == 0)
		return (ft_calloc(1, sizeof(char)));
	s += start;
	curlen = ft_strlen(s);
	if (curlen > len)
		curlen = len;
	substr = malloc(sizeof(char) * (curlen + 1));
	if (substr == 0)
		return (0);
	i = -1;
	while (++i < curlen)
		substr[i] = s[i];
	substr[i] = '\0';
	return (substr);
}
