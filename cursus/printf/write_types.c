/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:21:25 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/12 18:19:56 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
char			*ft_itoa(int n);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	*add_to_side(char *str, int nlen, char pad, int left)
{
	int		l;
	char	*ans;
	char	*cur;

	l = ft_strlen(str);
	if (l >= nlen)
		return (str);
	ans = (char *)malloc(sizeof(char) * nlen);
	cur = ans;
	if (!cur)
		return (str);
	if (left)
		ft_strlcpy(cur += l, str, nlen);
	while (l-- > nlen)
		*cur++ = pad;
	if (!left)
		ft_strlcpy(cur += l, str, nlen);
	free(str);
	return (ans);
}


int	write_type(char *str, t_printf* param)
{
	int	l;
	char	pad;
	int	i;
	// printf("WE HAVE %d", param->wid);
	i = 0;
	pad = ' ';
	if (param->zero)
		pad = '0';
	l = ft_strlen(str);
	if (param->prec != -1 && param->prec < l)
		l = param->prec;
	if (param->minus)
		write(1, str, l);
	while (i++ + l < param->wid){
		write(1, &pad, 1);
		
	}
	if (!param->minus)
		write(1, str, l);
	//write(1, "|", 1);
	free(str);
	if (l > param->wid)
		return (l);
	return (param->wid);
}

int	write_char(char c, t_printf* param)
{
	c++;
	param->conv = 0;
	return 0;
}

int	write_int(int n, t_printf* param)
{
	char	*str;

	//printf("\nn is %d\n", n);
	if(param->prec != -1)
		param->zero = 0;
	if (n == 0 && param->prec == 0)
		str = ft_calloc(1, sizeof(char));
	else if (n < 0 && (param->zero || param->prec))
	{
		write(1, "-", 1);
		str = ft_itoa(-n);// OVERFLOW ERROR :/
		param->wid--;
	}
	else
		str = ft_itoa(n);
	if (param->prec)
	{
		str = add_to_side(str, param->prec, '0', 0);
		if (param->minus)
			str = add_to_side(str, param->wid, ' ', 0);
		else
			str = add_to_side(str, param->wid, ' ', 1);
	}
	
	if (str){
		free(str);
		write(1, str, ft_strlen(str));
	}
	return (ft_strlen(str));
}



int	write_ptr(void* p, t_printf* param)
{
	p++;
	param->conv = 0;
	return 0;
}

int	write_hex(int n, t_printf* param, int is_upper)
{
	n++;
	param->conv = 0;
	is_upper++;
	return 0;
}

int	write_str(char* c, t_printf* param)
{
	return write_type(c, param);
}

