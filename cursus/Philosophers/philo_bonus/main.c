/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:56:07 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/02 18:57:37 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

unsigned long	get_time(void)
{
	struct timeval	a;

	gettimeofday(&a, 0);
	return (((a.tv_sec * 1000000 + a.tv_usec) / 1000) % 1000000);
}

int	inp(char *c)
{
	long	a;

	a = 0;
	while (*c >= '0' && *c <= '9' && a <= 2147483647)
		a = a * 10 + *c++ - '0';
	if (*c || a > 2147483647)
		return (-1);
	return ((int)a);
}

void	init_forks(int n, int ac, char *av[], pid_t *pids)
{
	int		i;
	t_param	p;

	i = -1;
	while (++i < n)
	{
		pids[i] = fork();
		if (!pids[i])
		{
			p = (t_param){.n_eat = -1, .t_eat = inp(av[3]),
				.n = i, .t_die = inp(av[2]), .t_slp = inp(av[4]),
				.write = sem_open("/write", O_CREAT, S_IRWXU, 1),
				.num_f = sem_open("/forks", O_CREAT, S_IRWXU, n)};
			if (ac == 6)
				p.n_eat = inp(av[5]);
			if (phil_process(&p))
				kill(pids[i], SIGKILL);
			exit(0);
		}
	}
}

int	main(int ac, char*av[])
{
	pid_t	*pids;
	int		n;

	n = inp(av[1]);
	sem_unlink("/forks");
	sem_unlink("/write");
	pids = malloc(sizeof(pid_t) * n);
	init_forks(n, ac, av, pids);
	while (--n > 0)
		waitpid(pids[n], 0, 0);
	free(pids);
	return (1);
}
