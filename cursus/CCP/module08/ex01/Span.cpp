/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:02:26 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/19 14:45:29 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int size)
{
	this->size = size;
	l = 0;
	a = new int[size];
}

Span::Span(const Span & other)
{
	size = other.size;
	l = other.l;
	a = new int[size];
	for (unsigned int i = 0; i < l; i++)
		a[i] = other.a[i];
}

Span &Span::operator=(const Span &other)
{
	delete[] a;
	size = other.size;
	l = other.l;
	a = new int[size];
	for (unsigned int i = 0; i < l; i++)
		a[i] = other.a[i];
	return *this;
}

Span::~Span()
{
	delete[] a;
}

void Span::addNumber(int num)
{
	if (l >= size)
		throw std::runtime_error::exception();
	a[l++] = num;
}

void Span::addNumbers(std::list<int>::iterator begin, std::list<int>::const_iterator end)
{
	std::list<int>::iterator i;
	for (i = begin; i != end; i++)
		this->addNumber(*i);
}

int Span::shortestSpan()
{
	int diff = __INT_MAX__;
	int arr[l];
	if (l < 2)
		throw std::runtime_error::exception();
	for (unsigned int i = 0; i < l; i++)
		arr[i] = a[i];
	std::sort(arr, arr + l);
	for (unsigned int i = 0; i < l - 1; i++)
		if (arr[i + 1] - arr[i] < diff)
			diff = arr[i + 1] - arr[i];
	return diff;
}

int Span::longestSpan()
{
	if (l < 2)
		throw std::runtime_error::exception();
	return (*std::max_element(a, a + l) - *std::min_element(a, a + l));
}
