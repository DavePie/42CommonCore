/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:27:00 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/16 18:19:40 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stacks *s)
{
	if (!s->a->start || !s->a->start->next)
		return (0);
	swap(s->a->start, s->a->end);
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
	if (!s->b->start || !s->b->start->next)
}