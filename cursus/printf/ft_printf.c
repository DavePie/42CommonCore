/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:40:29 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/11 17:11:51 by dvandenb         ###   ########.fr       */
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
#include <stdarg.h>
#include <stdio.h>

typedef struct s_convert_spec
{
	va_list	ap;
	int		sindex;
	int		aindex;
	size_t	width;
	size_t	precision;
	char	conversion;
}	t_convert_spec;

/**
 * Given a format string, return the number of stars (ie additional parameters) within
 * the first conversion.
 * 
 * Input: char array to process
 * Returns: an unsigned integer denoting the number of parameters needed
*/
static unsigned int	count_stars(const char *format)
{
	return (0);
}

/**
 * Gets index of the end of the conversion
 * Either a letter cspdiuxX or an unrecognized symbol
 * 
 * Input: char array to process
 * Returns: an unsigned integer denoting the index
*/
static unsigned int	get_end(const char *format)
{
	return (0);
}

/**
 * Formats and prints the given string
 * 
*/
int	ft_printf(const char *format, ...)
{
	va_list ap;
	int		total;

	total = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			unsigned int num_star = count_stars(format);
			int *stars = (int *)malloc(sizeof(int) * num_star);
			int i = -1;
			while (++i < num_star)
				stars[i] = va_arg(ap, int);
			total += process_convert(format, stars);
			format += get_end(format);
		}
		else
		{
			format++;
			total++;
		}
	}
	return (0);
}

static int process_convert(const char *format, int *stars)
{
	int		endI;
	char	ftype;
	int		strlen;
	char	*prestr;

	endI = get_end(format);
	ftype = format[endI];
	if (ftype == 'c')
		
	return (0);
}

static int	

int main()
{
	printf("%.1s%.1s%.1s%.1s%.1s%.1s))))\n", (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
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
	printf("6: |%*****04.2d|", 1,1,1,1,1,1234);
	// printf("\n");
	// printf("6: |%.-20f|", 12.565);
	// 	printf("\n");
	// printf("6: |%-20f|", 12.565);
	// printf("\n\n");
	return 0;
}
