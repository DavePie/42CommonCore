/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:45:41 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/20 17:59:47 by dvandenb         ###   ########.fr       */
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
	printf(" (%d)\nb:",s->a->len);
	while (b)
	{
		printf("%d, ", (b->i));
		b = b->next;
	}
	printf(" (%d)\n\n", s->b->len);
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

int	contains(int i, t_stacks *s)
{
	t_node	*cur;

	cur = s->a->start;
	while (cur)
	{
		if (cur->i == i)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int read_input(char *str, t_stacks *s)
{
	long	num;
	int		is_neg;

	num = 0;
	if (!*str)
		return (0);
	is_neg = *str == '-' && *str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + *str - '0';
		if (num > 2147483647 + is_neg)
			return (0);
		str++;
	}
	if (contains((int)num * (-2 * is_neg + 1), s))
		return (0);
	add_back(s->a, new_node((int)num));
	return (1);
}

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	min_moves(int x, int y)
{
	//printf("moves %d %d\n",x , y);
	if ((x > 0 && y > 0) || (x < 0 && y < 0))
		return (abs(x) + abs(y) - abs(x - y));
	return (abs(x) + abs(y));
}

/**
 * @brief Print and execture the minimum needed number of rotations
 * Positive: rotate up (top element removed)
 * Negative: rotate down (bottom element removed)
 * 
 * @param a 
 * @param b 
 * @param s 
 */
void	rotate(int	a, int	b, t_stacks *s)
{
	while (b > 0 && a > 0 && b-- && a-- && write(1, "rr\n", 3))
		rr(s);
	while (b < 0 && a < 0 && b++ && a++ && write(1, "rrr\n", 4))
		rrr(s);
	while (b > 0 && b-- && write(1, "rb\n", 3))
		rb(s);
	while (a > 0 && a-- && write(1, "ra\n", 3))
		ra(s);
	while (b < 0 && b++ && write(1, "rrb\n", 4))
		rrb(s);
	while (a < 0 && a++ && write(1, "rra\n", 4))
		rra(s);
}

/**
 * @brief 
 * 
 * @param a_i 
 * @param val 
 * @param s 
 * @param write_out 
 * @return int 
 */
int	best_insert_b(int a_i, t_node *n, t_stacks *s, int write_out)
{
	int		a_top;
	int		b_top;
	t_node	*cur;

	a_top = a_i;
	if (s->a->len - a_top < a_top)
		a_top = a_top - s->a->len;
	b_top = 0;
	cur = s->b->start;
	while (cur && !(cur->prev && cur->i > cur->prev->i
		&& (n->i < cur->prev->i || n->i > cur->i))
		&& !(cur->prev && cur->i < n->i && cur->prev->i > n->i)
		&& ++b_top)
		cur = cur->next;
	if (s->b->len - b_top < b_top)
		b_top = b_top - s->b->len;
	if (write_out)
	{
		rotate(a_top, b_top, s);
		pb(s);
		write(1, "pb\n", 3);
	}
	return min_moves(a_top, b_top);
}

void	best_insert_a(t_node *n, t_stacks *s)
{
	int		a_top;
	t_node	*cur;

	a_top = 0;
	cur = s->a->start;
	while (cur && !(cur->prev && cur->i < cur->prev->i
		&& (n->i > cur->prev->i || n->i < cur->i))
		&& !(cur->prev && cur->i > n->i && cur->prev->i < n->i)
		&& ++a_top)
		cur = cur->next;
	if (s->a->len - a_top < a_top)
		a_top = a_top - s->a->len;
	
	rotate(a_top, 0, s);
	pa(s);
	write(1, "pa\n", 3);
}

void	push_sort_b(t_stacks *s)
{
	t_node *cur;
	t_node *minn;
	int		min;
	int		temp;
	int		i;
	int		mini;

	while (s->a->len > 3)
	{
		i = -1;
		mini = 0;
		cur = s->a->start;
		min = s->b->len + 2;
		while (cur && ++i != -2)
		{
			temp = best_insert_b(i, cur, s, 0);
			if (temp < min)
			{
				minn = cur;
				min = temp;
				mini = i;
			}
			cur = cur->next;
		}
		best_insert_b(mini, minn, s, 1);
	}
}

int	sort_three(t_stacks *s)
{
	t_node	*n;

	n = s->a->start;
	if (!n || !n->next)
		return (0);
	if (!n->next->next && (n->i > n->next->i && write(1, "ra\n", 3)))
		return ra(s);
	if (!n->next->next)
		return (0);
	if ((n->i > n->next->i && n->i > n->next->next->i)
		&& write(1, "ra\n", 3))
		ra(s);
	n = s->a->start;
	if (n->next->i > n->next->next->i && n->next->i > n->i
		&& write(1, "rra\n", 4))
		rra(s);
	n = s->a->start;
	if (n->i > n->next->i && write(1, "sa\n", 3))
		sa(s);
	return (0);
}

void	reset_b(t_stacks *s)
{
	t_node	*cur;
	int		i;

	i = 0;
	cur = s->b->start;
	while (cur && !(cur->prev && cur->prev->i < cur->i) && ++i)
		cur = cur->next;
	if (s->b->len - i < i)
		i = i - s->b->len;
	rotate(0, i, s);
}

void	reset_a(t_stacks *s)
{
	t_node	*cur;
	int		i;

	i = 0;
	cur = s->a->start;
	while (cur && !(cur->prev && cur->prev->i > cur->i) && ++i)
		cur = cur->next;
	if (s->a->len - i < i)
		i = i - s->a->len;
	rotate(i, 0, s);
}

void	sort(t_stacks *s)
{
	push_sort_b(s);
	//print_stacks(s);
	//printf("sort three\n");
	sort_three(s);
	//print_stacks(s);
	reset_b(s);
	//print_stacks(s);
	while (s->b->start)
		best_insert_a(s->b->start, s);
		//print_stacks(s);
	reset_a(s);
	//print_stacks(s);
}

void	ft_lstclear(t_node **lst)
{
	t_node	*cur;
	t_node	*temp;

	if (!lst)
		return ;
	cur = *lst;
	while (cur)
	{
		temp = cur;
		cur = cur->next;
		free(temp);
	}
	*lst = 0;
}

int	main(int argc, char *argv[])
{
	t_stacks	*s;

	s = malloc(sizeof(t_stacks));
	if (!s && write(STDERR_FILENO, "Error\n", 6))
		return (0);
	s->a = malloc(sizeof(t_stack));
	if (!s->a && write(STDERR_FILENO, "Error\n", 6))
	{
		free(s);
		return (0);
	}
	s->b = malloc(sizeof(t_stack));
	if (!s->b && write(STDERR_FILENO, "Error\n", 6))
	{
		free(s->a);
		free(s);
		return (0);
	}
	*(s->a) = (t_stack){.start = 0, .end = 0, .len = 0};
	*(s->b) = (t_stack){.start = 0, .end = 0, .len = 0};
	argv++;
	while (--argc > 0)
	{
		if (!read_input(*argv, s) && write(STDERR_FILENO, "Error\n", 6))
		{
			ft_lstclear(&s->a->start);
			free(s->a);
			free(s->b);
			free(s);
			return(0);
		}
		argv++;
	}
	sort(s);
	print_stacks(s);
	return (0);
}