/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:19:55 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/19 14:48:54 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
int main()
{
	std::list<int> a;
	a.push_front(9);
	a.push_front(2);
	a.push_front(6);
	Span b(6);
	b.addNumbers(a.begin(), a.end());
	b.addNumber(2);
	b.addNumber(2);
	std::cout << "longest: " << b.longestSpan() << ", smallest: " << b.shortestSpan() << std::endl;
	b.addNumber(2);
	std::cout << "longest: " << b.longestSpan() << ", smallest: " << b.shortestSpan() << std::endl;
	try
	{
		b.addNumber(2);
	}
	catch (std::exception & e)
	{
		std::cout << "unable to add extra number  " << std::endl;
	}
	Span c(100000);
	for (int i = 0; i < 100000; i++)
	{
		c.addNumber(std::rand());
	}
	std::cout << "longest: " << c.longestSpan() << ", smallest: " << c.shortestSpan() << std::endl;
	c = b;
	std::cout << "longest: " << c.longestSpan() << ", smallest: " << c.shortestSpan() << std::endl;

}