/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:45:41 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/17 17:29:21 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_stacks(t_stacks *s)
{
	t_node *a;
	t_node *b;

	a = s->a->start;
	b = s->b->start;
	printf("a:");
	while (a)
	{
		printf("%d, ", (a->i));
		a = a->next;
	}
	printf("\nb:");
	while (b)
	{
		printf("%d, ", (b->i));
		b = b->next;
	}
	printf("\n\n");
}

void	add_table(t_stack *s, int *a, int n)
{
	while (n-- >1)
	{
		add_back(s, new_node(*(a++)));
	}
}

int	is_sorted(t_stacks *s)
{
	t_node *cur;
	if (s->b)
		return(0);
	if (!s->a->start)
		return (1);
	cur = s->a->start;
	while (cur->next)
	{
		if (cur->i > cur->next->i)
			return (0);
	}
	return (1);
}

// dynamic programming?
// have a hash function
/*
2 1 0

1 0 2
0 1 2
*/

// 2 1 3 6 5 8

// 8 2 1 3 6 5
// 5 8 2 1 3 6
// 6 5 8 2 1 3
// 
// things taken out have to be added back (+2)
// we want what we add back to be in order?
// 
// have two seperate lists, 
//
int	loop(t_stacks *s, int steps)
{
	pa(s);
	
}

int	main()
{
	int a[] = {1, 2, 3, 4};
	int b[] = {5, 6, 7, 8};
	t_stacks *s = malloc(sizeof(t_stacks));
	s->a = malloc(sizeof(t_stack));
	s->b = malloc(sizeof(t_stack));
	s->a->start = 0;
	s->a->end = 0;
	s->b->start = 0;
	s->b->end = 0;
	add_table(s->a, a, 4);
	is_sorted(s);
	add_table(s->b, b, 4);
	
	print_stacks(s);
	pa(s);
	pa(s);
	pa(s);
	print_stacks(s);
	pb(s);
	pb(s);
	pb(s);
	print_stacks(s);
	ra(s);
	rb(s);
	print_stacks(s);
	rr(s);
	print_stacks(s);
	rra(s);
	print_stacks(s);
	rrr(s);
	is_sorted(s);
	pa(s);
	pa(s);
	pa(s);
	print_stacks(s);
	
	/*
int	pa(t_stacks *s);
int	pb(t_stacks *s);
int	ra(t_stacks *s);
int	rb(t_stacks *s);
int	rr(t_stacks *s);
int	rra(t_stacks *s);
int	rrb(t_stacks *s);
int	rrr(t_stacks *s);*/
}