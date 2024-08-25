/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:47:14 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/30 14:02:31 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	ans;
	int	sign;

	ans = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
		ans = ans * 10 + sign * (*(str++) - '0');
	if (*str)
		return (0);
	return (ans);
}

int	signal_char_client(unsigned char c, int pid)
{
	unsigned char	cur;

	cur = 128;
	while (cur)
	{
		if (kill(pid, SIGUSR2 - !!(cur & c)) == -1)
			return (0);
		cur >>= 1;
		usleep(50);
	}
	return (1);
}

void	get_back_signal(int a)
{
	a++;
	ft_printf("Reply from server to pid %d\n", getpid());
}

int	main(int argc, char*argv[])
{
	int	server_pid;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
			return (0);
		signal(SIGUSR1, &get_back_signal);
		while (*argv[2])
		{
			signal_char_client(*argv[2], server_pid);
			argv[2]++;
		}
		signal_char_client(*argv[2], server_pid);
	}
	return (0);
}
