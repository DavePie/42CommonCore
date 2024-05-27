/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:08:55 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/12 13:15:48 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data t = (Data){.why = 0.1, .whatever = 123};
	std::cout << "pointer before: " << &t << std::endl;
	uintptr_t temp = Serializer::serialize(&t);
	Data *new_t = Serializer::deserialize(temp);
	std::cout << "pointer after: " << new_t << std::endl;
	if (new_t)
		std::cout << new_t->whatever << " " << new_t->why << std::endl;
	return (0);
}