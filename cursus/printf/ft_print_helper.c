/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:27:39 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/18 17:30:43 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief returns the number in the given base with the plus/space/minus in front
 * 
 * @param n 
 * @param b 
 * @param param 
 * @param is_neg 
 * @return char* 
 */
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

/**
 * @brief Set the param object
 * 
 * @param format 
 * @param prev_dot 
 * @param vals 
 */
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

/**
 * @brief Writes and returns the length of the conversion
 * given the conversion parameters and the parameter to write
 * 
 * @param param The format string to convert
 * @param ap The parameter to write
 * @return int (The length of the string)
 */
int	write_type(t_printf *param, va_list ap)
{
	char	c;

	c = param->conv;
	if (c == 'c')
		return (write_char((char)va_arg(ap, int), param));
	if (c == 'd' || c == 'i')
		return (write_int(va_arg(ap, int), param));
	if (c == 's')
		return (write_str(va_arg(ap, char *), param));
	if (c == 'u')
		return (write_int(va_arg(ap, unsigned int), param));
	if (c == 'x')
		return (write_hex(va_arg(ap, unsigned int), param, 0));
	if (c == 'X')
		return (write_hex(va_arg(ap, unsigned int), param, 1));
	if (c == 'p')
		return (write_ptr(va_arg(ap, void *), param));
	if (c == '%')
		return (write_char('%', param));
	if (c == '%')
		return (1);
	return (0);
}
