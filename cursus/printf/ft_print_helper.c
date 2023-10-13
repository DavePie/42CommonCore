/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:27:39 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/13 17:06:18 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ltoa(unsigned long n, char *b, int hide_zero, int is_neg)
{
	unsigned long	temp;
	int				len;
	char			*s;
	int				base;

	base = ft_strlen(b);
	if (hide_zero && !n)
		return (ft_calloc(1, sizeof(char)));
	temp = n;
	len = 1;
	while (temp != 0 && len++)
		temp /= base;
	len += (is_neg || n == 0);
	s = malloc(sizeof(char) * (len));
	if (!s)
		return (0);
	s[--len] = '\0';
	while (len > 0)
	{
		s[--len] = b[n % base];
		n /= base;
	}
	if (is_neg)
		s[0] = '-';
	return (s);
}

/**
 * Gets index of the end of the conversion
 * Either a letter cspdiuxX or an unrecognized symbol
 * 
 * Input: char array to process
 * Returns: an unsigned integer denoting the index
*/
unsigned int	get_end(const char *format)
{
	int	i;

	i = 0;
	while (format[i] && (ft_isdigit(format[i]) || ft_strchr("-.*", format[i])))
		i++;
	if (format[i] && ft_strchr("cspdiuxX", format[i]))
		i++;
	return (i);
}
