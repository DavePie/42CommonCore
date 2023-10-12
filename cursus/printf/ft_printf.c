/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:40:29 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/12 18:20:12 by dvandenb         ###   ########.fr       */
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

int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);

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
	while (format[i] && (ft_isdigit(format[i]) || ft_strchr("-.*", format[i])))
		i++;
	if (format[i] && ft_strchr("cspdiuxX", format[i]))
		i++;
	return (i);
}

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
static int	write_type(t_printf *param, va_list ap)
{
	char	c;

	c = param->conv;
	if (c == 'c')
		return write_char((char)va_arg(ap, int), param);
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
 * @return t_printf* (a struct containing the fields)
 */
static t_printf*	extract_param(const char *format, va_list ap)
{
	t_printf*	vals;
	int			end;
	int			i;

	// printf("Started at %c\n", *format);
	i = -1;
	vals = (t_printf*)malloc(sizeof(t_printf));
	if (!vals)
		return (0);
	end = get_end(format);
	vals->conv = format[end - 1];
	vals->prec = -1;
	vals->wid = 0;
	vals->minus = 0;
	vals->zero = 0;
	int curNum = 0;
	int prevDot = 0;
	while (++i < end)
	{
		// printf("cur num %d, cur prec %d, prevDot%d\n", curNum, vals->prec, prevDot);
		if (!ft_isdigit(format[i]))
		{
			if (format[i] == '*'){
			curNum = va_arg(ap, int);
			// printf("\nExtracted %d\n", curNum);

		}
			if (prevDot){
				vals->prec = curNum;
				// printf("\Set prec %d\n", curNum);
			}
			else if (curNum){
				vals->wid = curNum;
				// printf("\Set wid %d\n", curNum);
			}
			curNum = 0;
			prevDot = 0;
		} else if (format[i] == '0' && !prevDot && !ft_isdigit(format[i-1]))
			vals->zero = 1;
		else
			curNum = curNum * 10 + (format[i] - '0');
		if (format[i] == '.')
		{
			prevDot = 1;
			vals->prec = 0;
		}
		else if (format[i] == '-')
			vals->minus = 1;
	}
	if (vals->minus)
		vals->zero = 0;	
	return (vals);
}

static int	process_convert(const char *format, va_list ap)
{
	t_printf* vals;
	int		len;

	len = 0;
	vals = extract_param(format, ap);
	if (vals)
	{
		len = write_type(vals, ap);
	// 	printf("\nconversion result for %c:\n", vals->conv);
	// printf("zero: %d\n", vals->zero);
	// printf("minus: %d\n", vals->minus);
	// printf("prec: %d\n", vals->prec);
	// printf("width: %d\n", vals->wid);
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
			format ++;
			total += process_convert(format, ap);
			//printf("get end is %d\n", get_end(format + 1));
			format += get_end(format);
		}
		else
		{
			write(1, format, 1);
			format++;
			total++;
		}
	}
	va_end(ap);
	return (0);
}

int main()
{
	// printf("4: |%.1s%.1s%.1s%.1s%.1s%.1s))))|\n", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
	//ft_printf("ok","now", 123);
	// printf("1: |%5d%%\\$d|", 12, 24);
	// printf("\n");
	//printf("\n2: |%05c|", 'a');
	// printf("\n");
	// printf("3: |%5.d|",1234);
	// printf("\n");
	// printf("4: |%7.5d|",-1234);
	// printf("\n");
	// printf("5: |%7.3s|\n","1234", "abcdef");
	// // printf("\n");
	// printf("6: |%*****04.2d|\n", 1,1,1,1,1,1234);
	// printf("7: |%.0x|\n", 0);
	// printf("8: |%.0X|\n", 0);
	// printf("9: |%.0d|\n", 1);
	// printf("10: |%*..0d|\n", 2, 1);
	// printf("\n");
	// printf("6: |%.-20f|", 12.565);
	// 	printf("\n");
	// printf("6: |%-20f|", 12.565);
	// printf("\n\n");
	// char a[] = "%00**-d|\n";
	//ft_printf("4: |%-3.2s|\n","2");
	   printf("n: |%06.2d|\n",2222);
	   ft_printf("n: |%06.2d|\n",2222);
	   printf("n: |%06d|\n",2222);
	   
	   printf("s: |%-6.5s|\n","2222");
	   printf("n: |%-6.2d|\n",2222);
	   printf("s: |%-6.2s|\n","2222");
	// printf("test%3.*0s %d|\n", 2, "5678", 6);
	return 0;
}
