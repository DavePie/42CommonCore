/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:57:26 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/24 17:22:48 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_stack *cur)
{
	int		len;
	t_node	*n;

	n = cur->start;
	len = cur->len;
	while (--len > 0)
	{
		if (n->i > n->next->i)
			return (0);
		n = n->next;
	}
	return (1);
}
