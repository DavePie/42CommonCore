/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:22:45 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/22 17:54:49 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(t_list **first, t_list **other)
{
	t_list	*swap;

	swap = *first;
	*first = *other;
	*other = swap;
}

void	ft_swap_next(t_list *cur, t_list **other)
{
	t_list	*swap;

	swap = cur->next;
	cur->next = *other;
	*other = swap;
}

void	ft_sorted_list_merge(t_list **begin_list1,
	t_list *begin_list2, int (*cmp)())
{
	t_list	*cur;

	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	if (!begin_list2)
		return ;
	if ((*cmp)((*begin_list1)->data, begin_list2->data) > 0)
		ft_swap(begin_list1, &begin_list2);
	cur = *begin_list1;
	while (cur->next && begin_list2)
	{
		if ((*cmp)(cur->next->data, begin_list2->data) > 0)
			ft_swap_next(cur, &begin_list2);
		else
			cur = cur->next;
	}
	if (begin_list2)
		cur->next = begin_list2;
}
