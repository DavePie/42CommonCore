/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:27:39 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/18 14:20:30 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ltoa(unsigned long n, char *b, t_printf *param, int is_neg)
{
	unsigned long	temp;
	int				len;
	char			*s;
	int				base;

	base = ft_strlen(b);
	len = 1;
	if ((param->prec == 0) && !n)
		len--;
	temp = n;
	while (temp != 0 && len++)
		temp /= base;
	len += (n == 0) + (is_neg || param->space || param->plus);
	s = malloc(sizeof(char) * (len));
	if (!s)
		return (0);
	s[--len] = '\0';
	while (len > 0)
	{
		s[--len] = b[n % base];
		n /= base;
	}
	if (is_neg || param->plus || param->space)
		s[0] = 45 * is_neg + !is_neg * (param->plus * 11 + 32);
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
	while (format[i] && (ft_isdigit(format[i])
			|| ft_strchr("-.*# +", format[i])))
		i++;
	if (format[i] && ft_strchr("cspdiuxX%", format[i]))
		i++;
	return (i);
}

void	set_param(const char *format, int *prev_dot, t_printf *vals)
{
	if (*format == '.' && ++*prev_dot)
		vals->prec = 0;
	else if (*format == '-')
		vals->minus = 1;
	vals->hash = (vals->hash || *format == '#');
	vals->space = (vals->space || *format == ' ');
	vals->plus = (vals->plus || *format == '+');
}
