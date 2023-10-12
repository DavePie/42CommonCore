/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:22:02 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/12 10:37:36 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_printf
{
	va_list	ap;
	// int		s_in;
	// int		a_in;
	size_t	wid;
	size_t	prec;
	char	conv;
	int		zero;
	int		minus;
}	t_printf;
 int	write_char(char c, t_printf* param);
 int	write_int(int n, t_printf* param);
 int	write_ptr(void* p, t_printf* param);
 int	write_hex(int n, t_printf* param, int is_upper);
 int	write_str(char* c, t_printf* param);

#endif