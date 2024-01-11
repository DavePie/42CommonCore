/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:47:52 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/10 17:03:23 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try { Bureaucrat("hello", 0);}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;}
	try { Bureaucrat("hello", 151);}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;}

	Bureaucrat bob = Bureaucrat("bob", 150);
	Bureaucrat clone = bob;
	std::cout << clone;
	try {++bob;}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;}
}