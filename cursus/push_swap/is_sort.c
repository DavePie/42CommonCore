/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:57:26 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/25 11:01:11 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_stack *cur)
{
	int		len;
	t_node	*n;

	n = cur->start;
	len = cur->len;
	while (--len > 0)
	{
		if (n->i > n->next->i)
			return (0);
		n = n->next;
	}
	return (1);
}

int	pb(t_stacks *s, int print)
{
	if (!s->a->start)
		return (0);
	add_front(s->b, remove_front(s->a));
	if (print)
		write(1, "pb\n", 3);
	return (1);
}

int	rrr(t_stacks *s, int print)
{
	rra(s, 0);
	rrb(s, 0);
	add_front(s->b, remove_back(s->b));
	if (print)
		write(1, "rrr\n", 4);
	return (1);
}
