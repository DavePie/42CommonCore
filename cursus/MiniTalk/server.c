/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:47:14 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/27 15:39:39 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int	ans;
	int	sign;

	ans = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
		ans = ans * 10 + sign * (*(str++) - '0');
	return (ans);
}

int main(int argc, char*argv[])
{
    kill(ft_atoi(argv[1]), SIGUSR1);
    return 0;
}