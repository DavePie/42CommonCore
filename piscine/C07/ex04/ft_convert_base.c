/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:14:03 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/14 16:22:30 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
// b = 0, i = 0
int	get_base(char *base, int b, int i)
{
	while (base[b])
	{
		if (base[b] == '-' || base[b] == '+')
			return (0);
		i = 0;
		while (i < b)
			if (base[b] == base[i++])
				return (0);
		b++;
	}
	return (b);
}

// i = -1
int	get_index(char *base, char c, int i)
{
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

char	*get_base_string(char *base, long n, int b)
{
	int		i;
	int		sign;
	char	*ans;

	ans = (char *)malloc(sizeof(*ans) * 34);
	sign = 1;
	if (n < 0)
	{
		n *= -1;
		sign *= -1;
	}
	ans[33] = '\0';
	i = 32;
	if (n == 0)
		ans[i--] = base[0];
	while (n > 0)
	{
		ans[i--] = base[n % b];
		n /= b;
	}
	if (sign == -1)
		ans[i] = '-';
	else
		i++;
	return (&ans[i]);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		b_from;
	int		b_to;
	int		sign;
	long	temp_int;

	sign = 1;
	temp_int = 0;
	b_from = get_base(base_from, 0, 0);
	b_to = get_base(base_to, 0, 0);
	if (b_from < 2 || b_to < 2)
		return (0);
	while (*nbr == ' ' || *nbr == '\f' || *nbr == '\n'
		|| *nbr == '\r' || *nbr == '\t' || *nbr == '\v')
		nbr++;
	while (*nbr == '-' || *nbr == '+')
		if (*(nbr++) == '-')
			sign *= -1;
	while (get_index(base_from, *nbr, -1) >= 0)
	{
		temp_int = b_from * temp_int + get_index(base_from, *nbr++, -1);
		if ((sign == 1 && temp_int > 2147483647) || temp_int - 1 > 2147483647)
			return (0);
	}
	return (get_base_string(base_to, temp_int * sign, b_to));
}

/*int	main(void)
{
	char *n = "   \t \n  -+---F";
	char *b_from = "0123456789ABCDEF";
	char *b_to = "01";
	printf("%s\n", ft_convert_base(n, b_from, b_to));
	return 0;

}*/
