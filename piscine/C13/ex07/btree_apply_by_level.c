/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:14:42 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/20 21:14:44 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

int	initialize(int *vars, t_btree *root, t_btree ***prev)
{
	if (!root)
		return (0);
	*prev = (t_btree **)malloc(sizeof(t_btree *));
	(*prev)[0] = root;
	vars[0] = 1;
	vars[3] = 0;
	vars[2] = 1;
	return (1);
}

// size, i, j, level
void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
	int current_level, int is_first_elem))
{
	int		vars[4];
	t_btree	**prev;
	t_btree	**new;

	if (!initialize(vars, root, &prev))
		return ;
	while (vars[0] > 0)
	{
		new = (t_btree **)malloc(sizeof(t_btree *) * vars[0] * 2);
		vars[1] = 0;
		vars[2] = 0;
		while (vars[1] < vars[0])
		{
			applyf(prev[vars[1]]->item, vars[3], vars[1] == 0);
			if (prev[vars[1]]->left)
				new[vars[2]++] = prev[vars[1]]->left;
			if (prev[vars[1]]->right)
				new[vars[2]++] = prev[vars[1]]->right;
			vars[1]++;
		}
		free(prev);
		prev = new;
		vars[0] = vars[2];
		vars[3]++;
	}
}
