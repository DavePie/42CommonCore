/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:45:56 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 15:11:25 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "uknown";
	std::cout << "Animal " << type << " was created" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal " << type << " was created" << std::endl;
}

Animal::Animal(Animal &other)
{
	this->type = other.type;
	std::cout << "Animal " << type << " was created" << std::endl;
}

Animal &Animal::operator=(Animal &other)
{
	type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal " << type << " was destroyed" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal " << type << " made an unknown sound" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
