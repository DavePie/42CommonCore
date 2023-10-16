/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:37:24 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/16 18:16:20 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				i;
	
}	t_node;
typedef struct s_stack
{
	struct s_node	*start;
	struct s_node	*end;
}	t_stack;
typedef struct s_stacks
{
	t_stack *a;
	t_stack *b;
} t_stacks;
t_node	*add_front(t_stack *s, t_node *new);
t_node	*add_back(t_stack *s, t_node *new);
t_node	*remove_front(t_stack *s);
t_node	*remove_back(t_stack *s);
void	*swap(t_node *an, t_node *bn);

#endif