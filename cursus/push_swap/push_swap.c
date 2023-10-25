/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:45:41 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/25 10:18:37 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stacks(t_stacks *s)
// {
// 	t_node *a;
// 	t_node *b;
// 	a = s->a->start;
// 	b = s->b->start;
// 	printf("a:");
// 	while (a)
// 	{
// 		printf("%d, ", (a->i));
// 		a = a->next;
// 	}
// 	printf(" (%d)\nb:",s->a->len);
// 	while (b)
// 	{
// 		printf("%d, ", (b->i));
// 		b = b->next;
// 	}
// 	printf(" (%d)\n\n", s->b->len);
// }


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
			ft_lstclear(&s->a->start);
			free(s->a);
			free(s->b);
			free(s);
			return (0);
		}
		argv++;
	}
	if (!is_sort(s->a))
		sort(s);
	ft_lstclear(&s->a->start);
	free(s->a);
	free(s->b);
	free(s);
	return (0);
}
