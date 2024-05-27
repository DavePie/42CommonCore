/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:47:19 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 15:09:48 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog_animal")
{
	type = "Dog";
	std::cout << type << " created" << std::endl;
}

Dog::Dog(Dog &other) : Animal("Dog_animal")
{
	this->type = other.type;
	std::cout << type << " was created" << std::endl;
}

Dog &Dog::operator=(Dog &other)
{
	type = other.type;
	return *this;
}

Dog::~Dog()
{
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
