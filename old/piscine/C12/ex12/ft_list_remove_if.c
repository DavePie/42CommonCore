/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:50:10 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/19 17:50:12 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stdlib.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*cur;
	t_list	*temp;

	cur = *begin_list;
	prev = 0;
	while (cur)
	{
		if (!(*cmp)(cur->data, data_ref))
		{
			if (prev)
				prev->next = prev->next->next;
			else
				*begin_list = (*begin_list)->next;
			temp = cur;
			cur = cur->next;
			(*free_fct)(temp->data);
			free(temp);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
