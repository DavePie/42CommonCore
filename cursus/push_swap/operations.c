/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:27:00 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/23 17:47:05 by dvandenb         ###   ########.fr       */
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

int	rrr(t_stacks *s)
{
	if (!s->b->start || !s->b->start->next
		|| !s->a->start || !s->a->start->next)
		return (0);
	rra(s);
	rrb(s);
	return (1);
}

void	swap(t_node *an, t_node *bn)
{
	int	i;

	i = an->i;
	an->i = bn->i;
	bn->i = i;
}

// int	sb(t_stacks *s)
// {
// 	if (!s->b->start || !s->b->start->next)
// 		return (0);
// 	swap(s->b->start, s->b->start->next);
// 	return (1);
// }

// int	ss(t_stacks *s)
// {
// 	if (!s->b->start || !s->b->start->next
// 		|| !s->a->start || !s->a->start->next)
// 		return (0);
// 	sa(s);
// 	sb(s);
// 	return (1);
// }
