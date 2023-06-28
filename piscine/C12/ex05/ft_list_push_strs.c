/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:20:19 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/19 13:20:20 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data);

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*front;
	t_list	*prev;

	front = 0;
	prev = 0;
	while (size-- > 0)
	{
		front = ft_create_elem(*(strs++));
		front->next = prev;
		prev = front;
	}
	return (front);
}
