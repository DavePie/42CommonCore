/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:40:36 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/27 15:36:03 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...);

void test(int a)
{
    ft_printf("I got signal\n");
    exit(0);
}

int main(void)
{
    ft_printf("%d\n", (int)getpid());
    signal(SIGUSR1, test);
    while (1)
    {

    }
    return 0;
}