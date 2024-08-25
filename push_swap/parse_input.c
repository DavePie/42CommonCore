/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:18:54 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/25 10:19:24 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stacks	*initialize_t_stacks(void)
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
	return (s);
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

int	read_input(char *str, t_stacks *s)
{
	long	num;
	int		is_neg;

	while (*str)
	{
		num = 0;
		while (*str == ' ')
			str++;
		is_neg = (*str == '-');
		if (((*str == '+' || *str == '-') && str++)
			&& (*str < '0' || *str > '9'))
			return (0);
		while (*str && *str != ' ')
		{
			num = num * 10 + *str++ - '0';
			if (num - is_neg > M || *(str - 1) < '0' || *(str - 1) > '9')
				return (0);
		}
		if (*(str - 1) >= '0' && *(str - 1) <= '9'
			&& contains((int)num * (-2 * is_neg + 1), s))
			return (0);
		if (*(str - 1) >= '0' && *(str - 1) <= '9')
			add_back(s->a, new_node((int)num * (-2 * is_neg + 1)));
	}
	return (1);
}
