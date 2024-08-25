/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:13:15 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/14 09:21:39 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	get_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i - 1;
		while (j >= 0)
			if (base[i] == base[j--])
				return (0);
		i++;
	}
	return (i);
}

int	index_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	get_int_base(int b, char *str, char *base)
{
	int	ans;
	int	cur;

	ans = 0;
	while (*str != '\0')
	{
		cur = index_base(*str, base);
		if (cur != -1)
		{
			ans *= b;
			ans += cur;
		}
		else
			return (ans);
		str++;
	}
	return (ans);
}

int	ft_atoi_base(char *str, char *base)
{
	int	ans;
	int	sign;
	int	b;

	sign = 1;
	ans = 0;
	while (*str == ' ' || *str == '\t' || *str == '\f'
		|| *str == '\n' || *str == '\r' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	b = get_base(base);
	if (b < 1)
		return (0);
	return (sign * get_int_base(b, str, base));
}

/*int	main(void)
{
	int	d;

	d = ft_atoi_base("\t \n -+--+B", "AB");
	printf("%d\n", d);
}*/
