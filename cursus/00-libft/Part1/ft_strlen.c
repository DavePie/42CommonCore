/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:53:04 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/28 19:53:14 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long unsigned int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i++])
		;
	return (i - 1);
}
