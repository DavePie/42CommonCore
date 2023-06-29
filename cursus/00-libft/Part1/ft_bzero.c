/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:12:44 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/28 18:13:43 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *add, int c, long unsigned int len);

void	ft_bzero(void *s, long unsigned int n)
{
	ft_memset(s, 0, n);
}
