/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:11:10 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/19 13:11:11 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data);

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*cur;

	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	cur = *begin_list;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = ft_create_elem(data);
}
