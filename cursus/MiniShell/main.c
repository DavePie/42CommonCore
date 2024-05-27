/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:42:43 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/07 13:47:09 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char *av[])
{
	char *argv[] = {"path", "julia", 0};

	for (int i = 1; i < ac; i++){
		pid_t a = fork();
		if (!a)
		{
			int e = execv(av[i], argv);
			printf("error!\n");
			exit(0);
		}
		waitpid(a, 0, 0);
	}
	return (0);
}