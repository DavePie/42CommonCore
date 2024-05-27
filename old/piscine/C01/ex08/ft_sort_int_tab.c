/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:35:23 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/10 13:32:32 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	index;
	int	sorted;
	int	temp;

	sorted = 0;
	while (sorted == 0)
	{
		index = 0;
		sorted = 1;
		while (index < size - 1)
		{
			if (tab[index + 1] < tab[index])
			{
				sorted = 0;
				temp = tab[index];
				tab[index] = tab[index + 1];
				tab[index + 1] = temp;
			}
			index++;
		}
	}
}
