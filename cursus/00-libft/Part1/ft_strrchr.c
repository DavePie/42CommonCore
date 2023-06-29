/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:07:38 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/28 20:10:29 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ans;

	ans = 0;
	while (*s)
	{
		if (*s == c)
			ans = s;
		s++;
	}
	if (*s == c)
		return (s);
	return (ans);
}
