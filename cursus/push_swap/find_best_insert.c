/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:44:15 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/25 10:11:38 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	min_moves(int x, int y)
{
	if ((x > 0 && y > 0) || (x < 0 && y < 0))
	{
		if (abs(x) > abs(y))
			return (abs(x));
		return (abs(y));
	}
	return (abs(x) + abs(y));
}

void	rotate(int a, int b, t_stacks *s)
{
	while (b > 0 && a > 0 && b-- && a--)
		rr(s, 1);
	while (b < 0 && a < 0 && b++ && a++)
		rrr(s, 1);
	while (b > 0 && b--)
		rb(s, 1);
	while (a > 0 && a--)
		ra(s, 1);
	while (b < 0 && b++)
		rrb(s, 1);
	while (a < 0 && a++)
		rra(s, 1);
}

int	best_insert_b(int a_i, t_node *n, t_stacks *s, int write_out)
{
	int		a_top;
	int		b_top;
	t_node	*cur;

	a_top = a_i;
	if (s->a->len - a_top < a_top)
		a_top = a_top - s->a->len;
	b_top = 0;
	cur = s->b->start;
	while (cur && !(cur->prev && cur->i > cur->prev->i
			&& (n->i < cur->prev->i || n->i > cur->i))
		&& !(cur->prev && cur->i < n->i && cur->prev->i > n->i)
		&& ++b_top)
		cur = cur->next;
	if (s->b->len - b_top < b_top)
		b_top = b_top - s->b->len;
	if (write_out)
	{
		rotate(a_top, b_top, s);
		pb(s, 1);
	}
	return (min_moves(a_top, b_top));
}

void	best_insert_a(t_node *n, t_stacks *s)
{
	int		a_top;
	t_node	*cur;

	a_top = 0;
	cur = s->a->start;
	while (cur && !(cur->prev && cur->i < cur->prev->i
			&& (n->i > cur->prev->i || n->i < cur->i))
		&& !(cur->prev && cur->i > n->i && cur->prev->i < n->i)
		&& ++a_top)
		cur = cur->next;
	if (s->a->len - a_top < a_top)
		a_top = a_top - s->a->len;
	rotate(a_top, 0, s);
	pa(s, 1);
}
