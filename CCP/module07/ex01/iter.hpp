/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:24:00 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/12 18:28:38 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename Func> void	iter(T *a,  const size_t l, Func f);

template <typename T> void	iter(T *a,  const size_t l, void (*f)(const T &));

// template <typename T>
// void iter(T *ptr, size_t len, void (*f)(const T&));
template <class T>
void iter_print(T val);
#endif