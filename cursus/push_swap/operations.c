/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:27:00 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/24 17:20:06 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stacks *s)
{
	if (!s->a->start || !s->a->start->next)
		return (0);
	swap(s->a->start, s->a->start->next);
	write(1, "sa\n", 3);
	return (1);
}

int	pa(t_stacks *s)
{
	if (!s->b->start)
		return (0);
	add_front(s->a, remove_front(s->b));
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stacks *s)
{
	if (!s->a->start)
		return (0);
	add_front(s->b, remove_front(s->a));
	write(1, "pb\n", 3);
	return (1);
}

int	rrr(t_stacks *s)
{
	if (!s->b->start || !s->b->start->next
		|| !s->a->start || !s->a->start->next)
		return (0);
	add_front(s->a, remove_back(s->a));
	add_front(s->b, remove_back(s->b));
	write(1, "rrr\n", 4);
	return (1);
}

void	swap(t_node *an, t_node *bn)
{
	int	i;

	i = an->i;
	an->i = bn->i;
	bn->i = i;
}
