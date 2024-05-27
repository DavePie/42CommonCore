/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:35:27 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/25 12:54:53 by dvandenb         ###   ########.fr       */
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

int	free_helper(char *input)
{
	free(input);
	return (-1);
}

int	readstdin(t_stacks *s)
{
	char	*input;
	int		size;
	int		i;

	i = 0;
	input = malloc(sizeof(char) * 1000);
	if (!input)
		return (0);
	size = read(STDIN_FILENO, input, 1);
	while (size > 0)
	{
		if (input[i] == '\n')
		{
			input[i] = '\0';
			if (!exec_operations(input, s))
				return (free_helper(input));
			i = -1;
		}
		if (i >= 998)
			return (free_helper(input));
		size = read(STDIN_FILENO, &(input[++i]), 1);
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
	int			result;

	s = initialize_t_stacks();
	if (!s)
		return (0);
	argv++;
	while (--argc > 0)
	{
		if (!read_input(*argv, s) && write(2, "Error\n", 6) && free_structs(s))
			return (0);
		argv++;
	}
	if (!s->a->len && free_structs(s))
		return (0);
	result = readstdin(s);
	if (result == 1 && is_sort(s->a) && !s->b->start)
		write(1, "OK\n", 3);
	else if (result != -1)
		write(1, "KO\n", 3);
	else
		write(STDERR_FILENO, "Error\n", 6);
	free_structs(s);
	return (0);
}
