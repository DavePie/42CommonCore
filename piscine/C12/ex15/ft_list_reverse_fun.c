/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:21:50 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/19 16:21:51 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	get_len(t_list *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (nbr > 0 && begin_list)
	{
		begin_list = begin_list->next;
		nbr--;
	}
	return (begin_list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		len;
	int		i;
	void	*temp;
	t_list	*cur;
	t_list	*back;

	cur = begin_list;
	len = get_len(begin_list);
	i = 0;
	while (i < len / 2)
	{
		back = ft_list_at(cur, len - 1 - i * 2);
		temp = cur->data;
		cur->data = back->data;
		back->data = temp;
		i++;
		cur = cur->next;
	}
}
