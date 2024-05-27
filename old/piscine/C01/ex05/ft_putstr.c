/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:53:21 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/10 13:28:41 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index++] != '\0')
	{
	}	
	write(1, str, index - 1);
}
