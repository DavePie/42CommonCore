/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:22:02 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/13 17:06:55 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
/**
 * @brief 
 * size_t	wid;
 * size_t	prec;
 * char	conv;
 * int		zero;
 * int		minus;
 */
typedef struct s_printf
{
	int		wid;
	int		prec;
	char	conv;
	int		zero;
	int		minus;
}	t_printf;

size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				write_char(char c, t_printf *param);
int				write_int(long n, t_printf *param);
int				write_ptr(void *p, t_printf *param);
int				write_hex(unsigned long n, t_printf *param, int is_upper);
int				write_str(char *c, t_printf *param);
int				ft_printf(const char *format, ...);
//
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_ltoa(unsigned long n, char *b, int hide_zero, int is_neg);
int				write_num(t_printf *param, char *str);
int				write_strs(char *str, t_printf *param);
char			*add_zeros(char *num, int n);
char			*add_to_side(char *str, int nlen, char pad, int left);
int				write_type(t_printf *param, va_list ap);
unsigned int	get_end(const char *format);
#endif