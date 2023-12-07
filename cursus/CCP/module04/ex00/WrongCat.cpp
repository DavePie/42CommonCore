/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:47:19 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 15:25:52 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat_WrongAnimal")
{
	type = "WrongCat";
	std::cout << type << " created" << std::endl;
}

WrongCat::WrongCat(WrongCat &other) : WrongAnimal("WrongCat_WrongAnimal")
{
	this->type = other.type;
	std::cout << type << " was created" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &other)
{
	type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << type << " was destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << type << " goes meow" << std::endl;
}

std::string WrongCat::getType() const
{
	return type;
}
