/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:57:08 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/13 18:20:14 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(char c, t_printf *param)
{
	int		l;
	char	pad;
	int		i;

	i = 0;
	pad = ' ';
	if (param->zero)
		pad = '0';
	l = 1;
	if (param->prec != -1 && param->prec < l)
		l = param->prec;
	if (param->minus)
		write(1, &c, l);
	while (i++ + l < param->wid)
		write(1, &pad, 1);
	if (!param->minus)
		write(1, &c, l);
	if (l > param->wid)
		return (l);
	return (param->wid);
}

int	write_int(long n, t_printf *param)
{
	int	is_neg;

	is_neg = n < 0;
	if (n < 0)
		n *= -1;
	return (write_num(param, ft_ltoa(n, "0123456789",
				param->prec != -1, is_neg)));
}

int	write_hex(unsigned long n, t_printf *param, int is_upper)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (is_upper)
		hex = "0123456789ABCDEF";
	return (write_num(param, ft_ltoa(n, hex, param->prec != -1, 0)));
}

int	write_ptr(void *p, t_printf *param)
{
	write(1, "0x", 2);
	param->wid -= 2;
	return (2 + write_num(
			param, ft_ltoa((unsigned long)p,
				"0123456789abcdef", param->prec != -1, 0)));
}

int	write_str(char *c, t_printf *param)
{
	if (!c)
		c = "(null)";
	return (write_strs(c, param));
}
