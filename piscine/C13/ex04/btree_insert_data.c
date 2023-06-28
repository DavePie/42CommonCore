/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:29:43 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/20 18:29:45 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item);

void	btree_insert(t_btree *cur, void *item, int (*cmpf)(void *, void *))
{
	int		cmp;

	cmp = cmpf(cur->item, item);
	if (cmp >= 0)
	{
		if (!cur->left)
			cur->left = btree_create_node(item);
		else
			btree_insert(cur->left, item, cmpf);
	}
	else
	{
		if (!cur->right)
			cur->right = btree_create_node(item);
		else
			btree_insert(cur->right, item, cmpf);
	}
}

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	btree_insert(*root, item, cmpf);
}
