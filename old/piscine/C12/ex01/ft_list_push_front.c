/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:00:09 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/19 13:00:10 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data);

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*front;

	front = ft_create_elem(data);
	front->next = *begin_list;
	*begin_list = front;
}
