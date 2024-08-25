/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:30:43 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/08 11:00:10 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Created ice materia" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Destroyed ice materia" << std::endl;
}

Ice::Ice(Ice &other): AMateria("ice")
{
	std::cout << "Created ice materia" << std::endl;
	type = other.type;
}

Ice &Ice::operator=(Ice &other)
{
	type = other.type;
	return *this;
}

AMateria *Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "
		<< target.getName() << " *" << std::endl;
}
