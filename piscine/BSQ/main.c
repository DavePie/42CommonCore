/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchetela <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:19:20 by dchetela          #+#    #+#             */
/*   Updated: 2023/06/26 22:19:26 by dchetela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

void	write_ans_from_files(char **files, int num_files);

int	main(int argc, char **argv)
{
	if (argc == 1)
		write_ans_from_files(0, 0);
	else
		write_ans_from_files(argv + 1, argc - 1);
}
