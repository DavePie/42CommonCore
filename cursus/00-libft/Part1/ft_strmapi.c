/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:08:02 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/09 18:17:35 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		l;
	char	*ans;

	l = ft_strlen(s);
	ans = malloc(sizeof(char) * l);
	if (!ans)
		return (0);
	while (--l >= 0)
		ans[l] = f(l, s[l]);
	return (ans);
}