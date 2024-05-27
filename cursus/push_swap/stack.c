/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:46:44 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/23 17:41:59 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int i)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->i = i;
	new->next = 0;
	return (new);
}

t_node	*add_front(t_stack *s, t_node *new)
{
	if (!s->start)
	{
		s->start = new;
		s->end = new;
		s->len = 1;
		return (new);
	}
	s->len++;
	s->start->prev = new;
	new->prev = 0;
	new->next = s->start;
	s->start = new;
	return (new);
}

t_node	*add_back(t_stack *s, t_node *new)
{
	if (!s->start)
	{
		s->start = new;
		s->end = new;
		s->len = 1;
		return (new);
	}
	s->len++;
	s->end->next = new;
	new->prev = s->end;
	new->next = 0;
	s->end = new;
	return (new);
}

t_node	*remove_front(t_stack *s)
{
	t_node	*temp;

	if (!s->start)
		return (0);
	s->len--;
	temp = s->start;
	if (!temp->next)
	{
		s->end = 0;
		s->start = 0;
		return (temp);
	}
	temp->next->prev = 0;
	s->start = temp->next;
	temp->next = 0;
	return (temp);
}

t_node	*remove_back(t_stack *s)
{
	t_node	*temp;

	if (!s->end)
		return (0);
	temp = s->end;
	s->len--;
	if (!temp->prev)
	{
		s->start = 0;
		s->end = 0;
		return (temp);
	}
	temp->prev->next = 0;
	s->end = temp->prev;
	temp->prev = 0;
	return (temp);
}
