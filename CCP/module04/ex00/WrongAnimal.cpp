/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:45:56 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 15:11:25 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "uknown";
	std::cout << "WrongAnimal " << type << " was created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal " << type << " was created" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &other)
{
	this->type = other.type;
	std::cout << "WrongAnimal " << type << " was created" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &other)
{
	type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << type << " was destroyed" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal " << type << " made an unknown sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}
