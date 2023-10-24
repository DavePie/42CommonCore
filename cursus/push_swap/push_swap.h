/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:37:24 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/24 17:28:15 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

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
	int				len;
}	t_stack;
typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;
typedef struct s_min
{
	int	min;
	int	temp;
	int	i;
	int	mini;
}	t_min;
t_node	*add_front(t_stack *s, t_node *new);
t_node	*add_back(t_stack *s, t_node *new);
t_node	*remove_front(t_stack *s);
t_node	*remove_back(t_stack *s);
void	swap(t_node *an, t_node *bn);
int		pa(t_stacks *s);
int		pb(t_stacks *s);
int		ra(t_stacks *s);
int		rb(t_stacks *s);
int		rr(t_stacks *s);
int		rra(t_stacks *s);
int		rrb(t_stacks *s);
int		rrr(t_stacks *s);
int		sa(t_stacks *s);
t_node	*new_node(int i);
void	best_insert_a(t_node *n, t_stacks *s);
int		best_insert_b(int a_i, t_node *n, t_stacks *s, int write_out);
void	rotate(int a, int b, t_stacks *s);
void	sort(t_stacks *s);
int		is_sort(t_stack *cur);
#endif