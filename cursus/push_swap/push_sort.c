/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:46:19 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/24 18:13:48 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_sort_b(t_stacks *s)
{
	t_node	*cur;
	t_node	*minn;
	t_min	min;

	while (s->a->len > 3 && !is_sort(s->a))
	{
		min = (t_min){.i = -1, .mini = 0};
		cur = s->a->start;
		min.min = s->b->len + 2;
		while (cur && ++min.i != -2)
		{
			min.temp = best_insert_b(min.i, cur, s, 0);
			if (min.temp < min.min)
			{
				minn = cur;
				min.min = min.temp;
				min.mini = min.i;
			}
			cur = cur->next;
		}
		best_insert_b(min.mini, minn, s, 1);
	}
}

int	sort_three(t_stacks *s)
{
	t_node	*n;

	n = s->a->start;
	if (!n || !n->next)
		return (0);
	if (!n->next->next && (n->i > n->next->i))
		return (ra(s));
	if (!n->next->next)
		return (0);
	if ((n->i > n->next->i && n->i > n->next->next->i))
		ra(s);
	n = s->a->start;
	if (n->next->i > n->next->next->i && n->next->i > n->i)
		rra(s);
	n = s->a->start;
	if (n->i > n->next->i)
		sa(s);
	return (0);
}

void	reset_b(t_stacks *s)
{
	t_node	*cur;
	int		i;

	i = 0;
	cur = s->b->start;
	while (cur && !(cur->prev && cur->prev->i < cur->i) && ++i)
		cur = cur->next;
	if (s->b->len - i < i)
		i = i - s->b->len;
	rotate(0, i, s);
}

void	reset_a(t_stacks *s)
{
	t_node	*cur;
	int		i;

	i = 0;
	cur = s->a->start;
	while (cur && !(cur->prev && cur->prev->i > cur->i) && ++i)
		cur = cur->next;
	if (s->a->len - i < i)
		i = i - s->a->len;
	rotate(i, 0, s);
}

void	sort(t_stacks *s)
{
	push_sort_b(s);
	sort_three(s);
	reset_b(s);
	while (s->b->start)
		best_insert_a(s->b->start, s);
	reset_a(s);
}
