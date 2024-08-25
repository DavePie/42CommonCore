/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:23:47 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/12 18:28:31 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void iter_print(T val)
{
	std::cout << val << ", ";
}

template <typename T> void	iter(T *a,  const size_t l, void (*f)(const T &))
{
	for (size_t i = 0; i < l; i++)
		f(a[i]);
};

template <typename T, typename Func> void	iter(T *a,  const size_t l, Func f)
{
	for (size_t i = 0; i < l; i++)
		f(a[i]);
};

int main()
{
	int temp[5] = {5, 1, 2, 3, 4};
	iter(temp, 5, iter_print);
	std::cout << std::endl;
	std::string why[6] = {"r", "e", "i", "oo", "uuuu", "asdfasdf"};
	iter(why, 6, iter_print);
	return (0);
}