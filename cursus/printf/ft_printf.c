/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:40:29 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/12 11:36:10 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cspdiuxX%
/*

%c : unsigned char (no precision?)
%s : string        (min)
%p : pointer (hex)
%d, %i: int (no diff?)
%u : unsigned
%x : hexidecimal
%X : hex with captials
%% : %
*/
// % flags width.precision length modifier conversion

// Starts with %, YES
// zero or more flags YES			- 0 . *
// optional minimum field width YES 
// optional precision YES (probably)
// optional length modifier NO?
// ends with conversion specifier YES

// * : next argument
// 0 : padd with zeros. If - appears, ignore 0.
// . : precision (if 0 with 0, then empty)
// - : adjust left

#include <stdio.h>
#include "ft_printf.h"
typedef struct s_convert_spec
{
	va_list	ap;
	// int		s_in;
	// int		a_in;
	size_t	wid;
	size_t	prec;
	char	conv;
	int		zero;
	int		minus;
}	t_convert_spec;

/**
 * Gets index of the end of the conversion
 * Either a letter cspdiuxX or an unrecognized symbol
 * 
 * Input: char array to process
 * Returns: an unsigned integer denoting the index
*/
static unsigned int	get_end(const char *format)
{
	int	i;

	i = 0;
	while (format[i])//&& (ft_isdigit(format[i]) || ft_strchr("-.*", format[i])))
		i++;
	return (i);
}

/**
 * @brief Returns the number of additional parameters needed to format a string
 * 
 * @param format The string to format
 * @return unsigned int (number of *) until the end of the conversion
 */
static unsigned int	count_stars(const char *format)
{
	int	n;
	int	end;

	end = get_end(format);
	n = 0;
	while (end-- > 0)
		if (*format++ == '*')
			n++;
	return (n);
}

static 


/*
%c : unsigned char (no precision?)
%s : string        (min, max)
%p : pointer (hex, min)
%d, %i: int (no diff?)
%u : unsigned
%x : hexidecimal
%X : hex with captials
%% : %
*/
// POINTER VS HEX?

/**
 * @brief Writes and returns the length of the conversion given the conversion parameters and the parameter to write
 * 
 * @param param The format string to convert
 * @param ap The parameter to write
 * @return int (The length of the string)
 */
int	write_type(t_convert_spec *param, va_list ap)
{
	char	c;

	c = param->conv;
	if (c == 'c')
		return write_char(va_arg(ap, char), param);
	if (c == 'd' || c == 'i')
		return write_int(va_arg(ap, int), param);
	if (c == 's')
		return write_str(va_arg(ap, char*), param);
	if (c == 'u')
		return write_int(va_arg(ap, unsigned int), param);
	if (c == 'x')
		return write_hex(va_arg(ap, int), param, 0);
	if (c == 'X')
		return write_hex(va_arg(ap, int), param, 1);
	if (c == 'p')
		return write_ptr(va_arg(ap, void*), param);
	// return write_undefined(param, 1);
	return 0;
}

/**
 * @brief Given the format string and parameters, extract and return the flags, width, and precision
 * 
 * @param format The format string
 * @param ap The parameters
 * @return t_convert_spec* (a struct containing the fields)
 */
static t_convert_spec*	extract_param(const char *format, va_list ap)
{
	t_convert_spec*	vals;

	vals = (t_convert_spec*)malloc(sizeof(t_convert_spec));
	if (!vals)
		return (0);
	


	// unsigned int num_star = count_stars(format);
	// int *stars = (int *)malloc(sizeof(int) * num_star);
	// int i = -1;
	// while (++i < num_star)
	// 	stars[i] = va_arg(ap, int);
	// total += write_type(param, ap);
	// endI = get_end(format);
	// ftype = format[endI];

	
	return (vals);
}

static int	process_convert(const char *format, va_list ap)
{
	t_convert_spec* vals;
	int		len;

	format++;
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
 * @param ... additional parameters that are either variables to print or format parameters
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
			total += process_convert(format, ap);
			format += get_end(format);
		}
		else
		{
			format++;
			total++;
		}
	}
	va_end(ap);
	return (0);
}

int main()
{
	printf("4: |%.1s%.1s%.1s%.1s%.1s%.1s))))|\n", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
	//ft_printf("ok","now", 123);
	// printf("1: |%5d%%\\$d|", 12, 24);
	// printf("\n");
	//printf("\n2: |%05c|", 'a');
	// printf("\n");
	// printf("3: |%5.d|",1234);
	// printf("\n");
	// printf("4: |%7.5d|",-1234);
	// printf("\n");
	printf("5: |%7.3s|\n","1234", "abcdef");
	// printf("\n");
	printf("6: |%*****04.2d|\n", 1,1,1,1,1,1234);
	printf("7: |%.0x|\n", 0);
	printf("8: |%.0X|\n", 0);
	printf("9: |%.0d|\n", 1);
	// printf("\n");
	// printf("6: |%.-20f|", 12.565);
	// 	printf("\n");
	// printf("6: |%-20f|", 12.565);
	// printf("\n\n");
	return 0;
}
