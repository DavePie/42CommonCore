/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:45:10 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/19 13:48:36 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stdlib.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*prev;

	while (begin_list)
	{
		prev = begin_list;
		begin_list = begin_list->next;
		free_fct(prev->data);
		free(prev);
	}
}
