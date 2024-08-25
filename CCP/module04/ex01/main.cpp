/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:48:14 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 16:28:13 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Cat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* arr[10];
	for (int i = 0; i < 5; i++)
		arr[i] = new Dog();
	for (int i = 5; i < 10; i++)
		arr[i] = new Cat();

	for (int i = 0; i < 10; i++)
		delete arr[i];
	Dog d;
	{
		Dog c = d;
	}
	return (0);
}