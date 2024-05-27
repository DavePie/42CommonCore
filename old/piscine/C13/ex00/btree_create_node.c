/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:08:43 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/20 18:08:45 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*ans;

	ans = malloc(sizeof(t_btree));
	ans->item = item;
	ans->left = 0;
	ans->right = 0;
	return (ans);
}
