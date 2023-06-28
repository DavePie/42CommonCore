/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:26:10 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/19 18:26:19 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cur;

	cur = *begin_list1;
	if (!cur)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = begin_list2;
}
