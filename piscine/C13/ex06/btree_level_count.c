/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:07:52 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/20 21:07:54 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	ans;
	int	temp;

	if (!root)
		return (0);
	ans = btree_level_count(root->left);
	temp = btree_level_count(root->right);
	if (ans > temp)
		return (ans + 1);
	return (temp + 1);
}
