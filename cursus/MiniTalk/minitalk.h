/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:29:01 by dvandenb          #+#    #+#             */
/*   Updated: 2023/10/30 14:40:08 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# define BUFFER_SIZE 4069

int	ft_printf(const char *format, ...);

#endif