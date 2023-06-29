/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:11:31 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/29 10:41:23 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *haystack, const char *needle,
long unsigned int len)
{
	char				*hay;
	char				*need;
	long unsigned int	l;

	while (*haystack && len > 0)
	{
		*hay = haystack;
		*need = needle;
		l = len;
		while (*(need++) == *(hay++) && l-- > 0)
			if (*need == '\0')
				return (haystack);
		len--;
	}
	return (0);
}
