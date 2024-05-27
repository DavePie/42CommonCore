/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:01:11 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/19 11:01:15 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	add(int i, int j);
int	sub(int i, int j);
int	div(int i, int j);
int	mult(int i, int j);
int	mod(int i, int j);

void	set_array(int (*f[11])(int, int))
{
	f[0] = &mod;
	f[5] = &mult;
	f[6] = &add;
	f[8] = &sub;
	f[10] = &div;
}

int	atoi(char *c)
{
	int	sign;
	int	ans;

	ans = 0;
	sign = 1;
	while (*c == '+' || *c == '-')
		if (*(c++) == '-')
			sign *= -1;
	while (*c >= '0' && *c <= '9')
		ans = 10 * ans + sign * (*(c++) - '0');
	return (ans);
}

void	write_int(int nb)
{
	long	n;
	int		ans[10];
	int		i;
	char	cur;

	i = 0;
	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n == 0)
		write(1, "0", 1);
	while (n > 0)
	{
		ans[i++] = n % 10;
		n /= 10;
	}
	i--;
	while (i >= 0)
	{
		cur = ans[i--] + '0';
		write(1, &cur, 1);
	}
}

int	main(int argc, char **argv)
{
	int	ans;
	int	(*f[11])(int, int);
	int	a[2];

	set_array(f);
	ans = 0;
	if (argc != 4)
		return (0);
	if (!argv[2][1] && (argv[2][0] == '+' || argv[2][0] == '-'
		|| argv[2][0] == '/' || argv[2][0] == '*' || argv[2][0] == '%'))
	{
		a[0] = atoi(argv[1]);
		a[1] = atoi(argv[3]);
		if (a[1] == 0 && argv[2][0] == '%')
			write(1, "Stop : modulo by zero\n", 21);
		else if (a[1] == 0 && argv[2][0] == '/')
			write(1, "Stop : division by zero\n", 24);
		else
			ans = f[argv[2][0] - '%'](a[0], a[1]);
	}
	if (a[1] != 0 || (argv[2][0] != '%' && argv[2][0] != '/'))
		write_int(ans);
	if (a[1] != 0 || (argv[2][0] != '%' && argv[2][0] != '/'))
		write(1, "\n", 1);
	return (0);
}
