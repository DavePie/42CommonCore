/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:01:30 by dvandenb          #+#    #+#             */
/*   Updated: 2023/06/18 18:01:31 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_HEX_H
# define WRITE_HEX_H

void	ft_print_memory(char *addr, unsigned int size, int ptr, int inc);
void	print_pointer(int z, int inc);
int		get_len(char *str);
void	print_pointer_if_valid(int ptr, int itr);
int		get_size(int size, int file, char *chars);

#endif