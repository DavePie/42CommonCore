/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:27:00 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/25 11:00:43 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stacks *s, int print)
{
	if (!s->a->start || !s->a->start->next)
		return (0);
	swap(s->a->start, s->a->start->next);
	if (print)
		write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stacks *s, int print)
{
	if (!s->b->start || !s->b->start->next)
		return (0);
	swap(s->b->start, s->b->start->next);
	if (print)
		write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stacks *s, int print)
{
	sa(s, 0);
	sb(s, 0);
	if (print)
		write(1, "ss\n", 3);
	return (1);
}

int	pa(t_stacks *s, int print)
{
	if (!s->b->start)
		return (0);
	add_front(s->a, remove_front(s->b));
	if (print)
		write(1, "pa\n", 3);
	return (1);
}

void	swap(t_node *an, t_node *bn)
{
	int	i;

	i = an->i;
	an->i = bn->i;
	bn->i = i;
}
