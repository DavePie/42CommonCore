/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:47:19 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 16:10:08 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog_animal")
{
	type = "Dog";
	brain = new Brain();
	std::cout << type << " was created" << std::endl;
}

Dog::Dog(Dog &other) : Animal("Dog_animal")
{
	this->type = other.type;
	brain = new Brain();
	std::cout << type << " was created" << std::endl;
}

Dog &Dog::operator=(Dog &other)
{
	type = other.type;
	brain = other.brain;
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << type << " was destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << type << " goes woof" << std::endl;
}

std::string Dog::getType() const
{
	return type;
}
