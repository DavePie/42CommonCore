/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:51:02 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/12 18:37:05 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

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
	int arr[] = {4, 3, 1, 2};
	std::vector<int> v;
	std::list<int> l(arr, arr + 4);
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
	try
	{easyfind(v, 10);}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	for (int i = 1; i < 5; i++)
		std::cout << easyfind(v, i) << std::endl;
	return (0);
}