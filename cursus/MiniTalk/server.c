/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:40:36 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/30 14:33:18 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_buf
{
	int				pid;
	char			cur;
	int				cur_bit;
	char			*buff;
	int				cur_i;
	struct s_buf	*next;
}	t_buf;

t_buf	*get_t_buffer(int pid, t_buf **sb)
{
	t_buf	*new;
	t_buf	*b;

	b = *sb;
	while (b && b->pid != pid && b->next)
		b = b->next;
	if (b && b->pid == pid)
		return (b);
	new = (t_buf *)malloc(sizeof(t_buf));
	if (!new)
		return (0);
	*new = (t_buf){.pid = pid,
		.buff = (char *)malloc(sizeof(char) * BUFFER_SIZE)};
	if (!new->buff)
	{
		free(new);
		return (0);
	}
	if (b)
		b->next = new;
	else
		*sb = new;
	return (new);
}

void	store_char(t_buf *c)
{
	c->buff[c->cur_i] = c->cur;
	if (c->cur == '\0')
	{
		ft_printf("%s", c->buff);
		c->cur_i = -1;
		kill(c->pid, SIGUSR1);
	}
	if (c->cur_i == BUFFER_SIZE - 2)
	{
		c->buff[c->cur_i + 1] = '\0';
		ft_printf("%s", c->buff);
		c->cur_i = -1;
	}
	c->cur = 0;
	c->cur_bit = 0;
	c->cur_i++;
}

void	handle_bit(int a, siginfo_t *input, void *other)
{
	static t_buf	*b;
	t_buf			*c;

	other++;
	c = get_t_buffer(input->si_pid, &b);
	c->cur <<= 1;
	if (a == SIGUSR1)
		c->cur++;
	c->cur_bit++;
	if (c->cur_bit == 8)
		store_char(c);
}

int	mysignal(int sig)
{
	int					r;
	struct sigaction	s;

	s.sa_sigaction = handle_bit;
	sigemptyset(&s.sa_mask);
	s.sa_flags = SA_SIGINFO;
	r = sigaction(sig, &s, NULL);
	return (r);
}

int	main(void)
{
	struct sigaction	sig;

	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	ft_printf("%d\n", (int)getpid());
	mysignal(SIGUSR1);
	mysignal(SIGUSR2);
	while (1)
		;
	return (0);
}
