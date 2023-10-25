/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:35:27 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/25 10:38:06 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_operations(char *input, t_stacks *s)
{
	if (!ft_strncmp(input, "sa", 3))
		sa(s, 0);
	else if (!ft_strncmp(input, "sb", 3))
		sb(s, 0);
	else if (!ft_strncmp(input, "ss", 3))
		ss(s, 0);
	else if (!ft_strncmp(input, "pa", 3))
		pa(s, 0);
	else if (!ft_strncmp(input, "pb", 3))
		pb(s, 0);
	else if (!ft_strncmp(input, "ra", 3))
		ra(s, 0);
	else if (!ft_strncmp(input, "rb", 3))
		rb(s, 0);
	else if (!ft_strncmp(input, "rr", 3))
		rr(s, 0);
	else if (!ft_strncmp(input, "rra", 4))
		rra(s, 0);
	else if (!ft_strncmp(input, "rrb", 4))
		rrb(s, 0);
	else if (!ft_strncmp(input, "rrr", 4))
		rrr(s, 0);
	else
		return (0);
	return (1);
}

int	readstdin(t_stacks *s)
{
	char	*input;
	int		size;

	input = malloc(sizeof(char) * 5);
	size = read(STDIN_FILENO, input, 5);
	if (size >= 5)
		return (0);
	while (size > 0)
	{
		input[size - 1] = '\0';
		if (!exec_operations(input, s))
			return (0);
		size = read(STDIN_FILENO, input, 5);
	}
	free(input);
	return (1);
}

int	free_structs(t_stacks *s)
{
	ft_lstclear(&s->a->start);
	ft_lstclear(&s->b->start);
	free(s->a);
	free(s->b);
	free(s);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stacks	*s;

	s = initialize_t_stacks();
	if (!s)
		return (0);
	argv++;
	while (--argc > 0)
	{
		if (!read_input(*argv, s) && write(STDERR_FILENO, "Error\n", 6))
		{
			free_structs(s);
			return (0);
		}
		argv++;
	}
	if (readstdin(s) && is_sort(s->a) && !s->b->start)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_structs(s);
	return (0);
}
