/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:23:54 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/07 13:33:37 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	char	*neg;
	char	*pos;

	neg = "N";
	pos = "P";
	if (n < 0)
	{
		write(1, neg, 1);
	}
	else
	{
		write(1, pos, 1);
	}
}
