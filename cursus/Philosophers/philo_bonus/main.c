/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:56:07 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/03 11:16:35 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

unsigned long	get_time(void)
{
	struct timeval	a;

	gettimeofday(&a, 0);
	return ((a.tv_sec * 1000000 + a.tv_usec));
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

void	safe_exit(pid_t *pids, int i, sem_t *w, sem_t *n)
{
	pid_t	temp;

	sem_close(w);
	sem_close(n);
	temp = pids[i];
	free(pids);
	kill(pids[i], SIGKILL);
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
			p = (t_param){.n_eat = -1, .t_eat = inp(av[3]) * 1000,
				.n = i, .t_die = inp(av[2]) * 1000,
				.t_slp = inp(av[4]) * 1000,
				.write = sem_open("/write", O_CREAT, S_IRWXU, 1),
				.num_f = sem_open("/forks", O_CREAT, S_IRWXU, n)};
			if (ac == 6)
				p.n_eat = inp(av[5]);
			if (phil_process(&p))
				safe_exit(pids, i, p.write, p.num_f);
			exit(0);
		}
	}
}

int	main(int ac, char*av[])
{
	pid_t	*pids;
	int		n;

	if ((ac != 5 && ac != 6) || inp(av[1]) == -1 || inp(av[2]) == -1
		|| inp(av[3]) == -1 || inp(av[4]) == -1
		|| (ac == 6 && inp(av[5]) == -1))
		return (0);
	n = inp(av[1]);
	sem_unlink("/forks");
	sem_unlink("/write");
	pids = malloc(sizeof(pid_t) * n);
	if (!pids)
		return (0);
	init_forks(n, ac, av, pids);
	while (--n > 0)
		waitpid(pids[n], 0, 0);
	free(pids);
	sem_close(sem_open("/write", O_CREAT, S_IRWXU, 1));
	sem_close(sem_open("/forks", O_CREAT, S_IRWXU, n));
	return (1);
}
