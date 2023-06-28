/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:41:15 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/20 18:41:17 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	t_btree	*cur;

	if (!root)
		return (0);
	cur = btree_search_item(root->left, data_ref, cmpf);
	if (cur)
		return (cur);
	if (!cmpf(root->item, data_ref))
		return (root->item);
	cur = btree_search_item(root->right, data_ref, cmpf);
	return (cur);
}
