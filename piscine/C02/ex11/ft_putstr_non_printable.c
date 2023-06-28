/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:39:07 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/12 15:58:15 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>
void	ft_putstr_non_printable(char *str);

void	print_c(char c)
{
	write(1, &c, 1);
}

void	write_hex(unsigned char c)
{
	print_c('\\');
	if (c / 16 < 10)
		print_c(c / 16 + '0');
	else
		print_c(c / 16 - 10 + 'a');
	if (c % 16 < 10)
		print_c(c % 16 + '0');
	else
		print_c(c % 16 - 10 + 'a');
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < ' ' || *str > '~')
			write_hex((unsigned char)*str);
		else
			write(1, str, 1);
		str++;
	}
}

/*int	main(){
	char *input = "\xfe";
	ft_putstr_non_printable(input);
}*/
