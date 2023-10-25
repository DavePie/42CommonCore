/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:37:24 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/25 10:43:40 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# define M 2147483647

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
t_node		*add_front(t_stack *s, t_node *new);
t_node		*add_back(t_stack *s, t_node *new);
t_node		*remove_front(t_stack *s);
t_node		*remove_back(t_stack *s);
void		swap(t_node *an, t_node *bn);
int			pa(t_stacks *s, int print);
int			pb(t_stacks *s, int print);
int			ra(t_stacks *s, int print);
int			rb(t_stacks *s, int print);
int			rr(t_stacks *s, int print);
int			rra(t_stacks *s, int print);
int			rrb(t_stacks *s, int print);
int			rrr(t_stacks *s, int print);
int			sa(t_stacks *s, int print);
int			ss(t_stacks *s, int print);
int			sb(t_stacks *s, int print);
t_node		*new_node(int i);
void		best_insert_a(t_node *n, t_stacks *s);
int			best_insert_b(int a_i, t_node *n, t_stacks *s, int write_out);
void		rotate(int a, int b, t_stacks *s);
void		sort(t_stacks *s);
int			is_sort(t_stack *cur);
int			read_input(char *str, t_stacks *s);
t_stacks	*initialize_t_stacks(void);
char		*get_next_line(int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t a);
void		ft_lstclear(t_node **lst);
#endif