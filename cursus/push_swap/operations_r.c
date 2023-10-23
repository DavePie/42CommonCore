/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:40:33 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/23 17:40:40 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!s->b->start || !s->b->start->next
		|| !s->a->start || !s->a->start->next)
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
