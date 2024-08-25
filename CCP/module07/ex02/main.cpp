/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:04:05 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/12 15:39:31 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	Array<int> a;
	std::cout << a.size() << std::endl;
	
	Array<int> b(20);
	std::cout << b.size() << std::endl;
	
	for (int i = 0; i < 20; i++)
		b[i] = 10 - i;
	a = b;
	for (int i = 0; i < 20; i++)
		std::cout << a[i] << ", ";
	std::cout << std::endl;
	for (int i = 0; i < 20; i++)
		b[i] = 0;
	for (int i = 0; i < 20; i++)
		std::cout << a[i] << ", ";
	std::cout << std::endl;
	for (int i = 0; i < 20; i++)
		a[i] = 1;
		
	Array<std::string>ss(2);
	ss[0] = "hello";
	ss[1] = "there";
	for (int i = 0; i < 2; i++)
		std::cout << ss[i] << std::endl;
	Array<std::string>ss2(ss);
	
	std::cout<< std::endl;
}