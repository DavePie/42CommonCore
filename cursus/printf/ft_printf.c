/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:40:29 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/13 17:07:07 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf	*create_new_param(char conv, int *cur_num, int *prev_dot)
{
	t_printf	*vals;

	vals = (t_printf *)malloc(sizeof(t_printf));
	if (!vals)
		return (0);
	vals->conv = conv;
	vals->prec = -1;
	vals->wid = 0;
	vals->minus = 0;
	vals->zero = 0;
	cur_num = 0;
	prev_dot = 0;
	return (vals);
}

static void	store_num(int is_digit, int *cur_num, int *prev_dot, t_printf *vals)
{
	if (!is_digit)
	{
		*cur_num = 0;
		*prev_dot = 0;
	}
	if (*prev_dot)
		vals->prec = *cur_num;
	else if (*cur_num)
		vals->wid = *cur_num;
}

/**
 * @brief Given the format string and parameters,
 * extract and return the flags, width, and precision
 * 
 * @param format The format string
 * @param ap The parameters
 * @return t_printf* (a struct containing the fields)
 */
static t_printf	*extract_param(const char *format, va_list ap)
{
	t_printf	*vals;
	int			end;
	int			cur_num;
	int			prev_dot;

	end = get_end(format);
	vals = create_new_param(format[end - 1], &cur_num, &prev_dot);
	while (0 < end--)
	{
		if (*format == '*')
			cur_num = va_arg(ap, int);
		store_num(ft_isdigit(*format), &cur_num, &prev_dot, vals);
		if (*format == '0' && !prev_dot && !ft_isdigit(*(format - 1)))
			vals->zero = 1;
		else if (ft_isdigit(*format))
			cur_num = cur_num * 10 + (*format - '0');
		if (*format == '.' && ++prev_dot)
			vals->prec = 0;
		else if (*format == '-')
			vals->minus = 1;
		format++;
	}
	if (vals->minus)
		vals->zero = 0;
	return (vals);
}

static int	process_convert(const char *format, va_list ap)
{
	t_printf	*vals;
	int			len;

	len = 0;
	vals = extract_param(format, ap);
	if (vals)
	{
		len = write_type(vals, ap);
		free(vals);
	}
	return (len);
}

/**
 * @brief Formats and prints the given string
 * 
 * @param format the given string to format and print
 * @param ... additional parameters that are either variables
 * to print or format parameters
 * @return int 
 */
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total;

	total = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%' && ++total && write(1, format, 1) && format++)
				continue ;
			total += process_convert(format, ap);
			format += get_end(format);
			continue ;
		}
		write(1, format, 1);
		format++;
		total++;
	}
	va_end(ap);
	return (total);
}
