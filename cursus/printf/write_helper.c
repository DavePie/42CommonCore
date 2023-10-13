/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:21:25 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/13 17:02:25 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_to_side(char *str, int nlen, char pad, int left)
{
	int		l;
	char	*ans;
	char	*cur;

	l = ft_strlen(str);
	if (l >= nlen)
		return (str);
	ans = (char *)malloc(sizeof(char) * (nlen + 1));
	cur = ans;
	if (!cur)
		return (str);
	if (!left)
		ft_strlcpy(cur += l, str, nlen + 1);
	while (nlen-- > l)
		*cur++ = pad;
	if (left)
		ft_strlcpy(cur += l, str, nlen + 1);
	free(str);
	return (ans);
}

char	*add_zeros(char *num, int n)
{
	int		l;
	char	*ans;
	char	*cur;

	l = ft_strlen(num);
	if (n <= l)
		return (num);
	ans = (char *)malloc(sizeof(char) * (n + 1));
	cur = ans;
	if (!ans)
		return (0);
	if (num[0] == '-')
		*cur++ = '-';
	while (n > l++)
		*cur++ = '0';
	l = ft_strlen(num);
	ft_strlcpy(cur, (char *)(num + (num[0] == '-')), l + 1);
	ans[n] = '\0';
	free(num);
	num = ans;
	return (num);
}

int	write_strs(char *str, t_printf *param)
{
	int		l;
	char	pad;
	int		i;

	i = 0;
	pad = ' ';
	if (param->zero)
		pad = '0';
	l = ft_strlen(str);
	if (param->prec != -1 && param->prec < l)
		l = param->prec;
	if (param->minus)
		write(1, str, l);
	while (i++ + l < param->wid)
		write(1, &pad, 1);
	if (!param->minus)
		write(1, str, l);
	if (l > param->wid)
		return (l);
	return (param->wid);
}

int	write_num(t_printf *param, char *str)
{
	int		final_length;

	if (param->prec != -1)
		param->zero = 0;
	if (param->prec != -1)
	{
		str = add_zeros(str, param->prec);
		str = add_to_side(str, param->wid, ' ', !param->minus);
	}
	else if (param->zero)
		str = add_zeros(str, param->wid);
	else
		str = add_to_side(str, param->wid, ' ', !param->minus);
	final_length = ft_strlen(str);
	if (str)
	{
		write(1, str, ft_strlen(str));
		free(str);
	}
	return (final_length);
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
	return (0);
}
