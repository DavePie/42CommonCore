/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:47:19 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 15:54:26 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat_animal")
{
	type = "Cat";
	brain = new Brain();
	std::cout << type << " created" << std::endl;
}

Cat::Cat(Cat &other) : Animal("Cat_animal")
{
	this->type = other.type;
	brain = new Brain();
	std::cout << type << " was created" << std::endl;
}

Cat &Cat::operator=(Cat &other)
{
	type = other.type;
	brain = other.brain;
	return *this;
}

Cat::~Cat()
{
	std::cout << type << " was destroyed" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << type << " goes meow" << std::endl;
}

std::string Cat::getType() const
{
	return type;
}
