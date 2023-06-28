/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:55:42 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/19 18:55:45 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*swap_nodes(t_list *prev, t_list *cur)
{
	t_list	*next;

	if (prev)
		prev->next = cur->next;
	next = cur->next->next;
	cur->next->next = cur;
	cur->next = next;
	if (!prev)
		return (cur);
	return (prev);
}

void	update_itr(t_list **prev, t_list **temp)
{
	*prev = *temp;
	*temp = (*temp)->next;
}

void	sort_itr(t_list **temp, t_list **prev, t_list **begin_list, int *sorted)
{
	if ((*temp) == (*begin_list))
		*begin_list = (*temp)->next;
	(*prev) = swap_nodes((*prev), (*temp));
	(*temp) = (*prev)->next;
	*sorted = 0;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		sorted;
	t_list	*temp;
	t_list	*prev;

	if (!*begin_list)
		return ;
	sorted = 0;
	while (!sorted)
	{
		temp = (*begin_list);
		prev = 0;
		sorted = 1;
		while (temp->next)
		{
			if ((*cmp)(temp->data, temp->next->data) > 0)
				sort_itr(&temp, &prev, begin_list, &sorted);
			else
				update_itr(&prev, &temp);
		}
	}
}
