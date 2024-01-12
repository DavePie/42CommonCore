/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:51:02 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/12 16:57:07 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

template <class T>
inline int easyfind(T c, int i)
{
	for (typename T::iterator it = c.begin(); it != c.end(); it++)
		if (*it == i)
			return *it;
	throw std::runtime_error("Element does not exist");
}

int main()
{
	std::vector<int> v;
	std::string a;
	try
	{easyfind(a, 1);}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{easyfind(v, 1);}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	for (int i = 0; i < 10; i++)
		std::cout << easyfind(v, i) << std::endl;
	return (0);
}