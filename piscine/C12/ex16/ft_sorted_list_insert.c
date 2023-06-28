/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:50:28 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/19 20:50:30 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	twentyfive(t_list *node, t_list *cur, int (*cmp)(), void *data)
{
	if ((*cmp)(cur->next->data, data) >= 0)
	{
		node->next = cur->next;
		cur->next = node;
		return (1);
	}
	return (0);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*node;
	t_list	*cur;

	node = ft_create_elem(data);
	if (!*begin_list)
	{
		*begin_list = node;
		return ;
	}
	if ((*cmp)((*begin_list)->data, data) >= 0)
	{
		node->next = *begin_list;
		*begin_list = node;
		return ;
	}
	cur = *begin_list;
	while (cur->next)
	{
		if (twentyfive(node, cur, cmp, data))
			return ;
		cur = cur->next;
	}
	cur->next = node;
}
