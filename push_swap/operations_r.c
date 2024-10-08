/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:40:33 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/25 11:00:32 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stacks *s, int print)
{
	if (!s->a->start || !s->a->start->next)
		return (0);
	add_back(s->a, remove_front(s->a));
	if (print)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stacks *s, int print)
{
	if (!s->b->start || !s->b->start->next)
		return (0);
	add_back(s->b, remove_front(s->b));
	if (print)
		write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stacks *s, int print)
{
	ra(s, 0);
	rb(s, 0);
	if (print)
		write(1, "rr\n", 3);
	return (1);
}

int	rra(t_stacks *s, int print)
{
	if (!s->a->start || !s->a->start->next)
		return (0);
	add_front(s->a, remove_back(s->a));
	if (print)
		write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stacks *s, int print)
{
	if (!s->b->start || !s->b->start->next)
		return (0);
	add_front(s->b, remove_back(s->b));
	if (print)
		write(1, "rrb\n", 4);
	return (1);
}
