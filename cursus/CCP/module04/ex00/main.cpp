/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:48:14 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 15:32:29 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Cat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	k->makeSound();
	delete meta;
	delete i;
	delete j;
	delete k;
	return (0);
}