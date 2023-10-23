/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:27:00 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/23 15:42:12 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stacks *s)
{
	if (!s->a->start || !s->a->start->next)
		return (0);
	swap(s->a->start, s->a->start->next);
	return (1);
}

int	sb(t_stacks *s)
{
	if (!s->b->start || !s->b->start->next)
		return (0);
	swap(s->b->start, s->b->start->next);
	return (1);
}

int	ss(t_stacks *s)
{
	if (!s->b->start || !s->b->start->next || !s->a->start || !s->a->start->next)
		return (0);
	sa(s);
	sb(s);
	return (1);
}

int	pa(t_stacks *s)
{
	if (!s->b->start)
		return (0);
	add_front(s->a, remove_front(s->b));
	return (1);
}

int	pb(t_stacks *s)
{
	if (!s->a->start)
		return (0);
	add_front(s->b, remove_front(s->a));
	return (1);
}

int	ra(t_stacks *s)
{
	if (!s->a->start || !s->a->start->next)
		return (0);
	add_back(s->a, remove_front(s->a));
	return (1);
}

int	rb(t_stacks *s)
{
	if (!s->b->start || !s->b->start->next)
		return (0);
	add_back(s->b, remove_front(s->b));
	return (1);
}

int	rr(t_stacks *s)
{
	if (!s->b->start || !s->b->start->next || !s->a->start || !s->a->start->next)
		return (0);
	ra(s);
	rb(s);
	return (1);
}

int	rra(t_stacks *s)
{
	if (!s->a->start || !s->a->start->next)
		return (0);
	add_front(s->a, remove_back(s->a));
	return (1);
}

int	rrb(t_stacks *s)
{
	if (!s->b->start || !s->b->start->next)
		return (0);
	add_front(s->b, remove_back(s->b));
	return (1);
}

int	rrr(t_stacks *s)
{
	if (!s->b->start || !s->b->start->next || !s->a->start || !s->a->start->next)
		return (0);
	rra(s);
	rrb(s);
	return (1);
}

