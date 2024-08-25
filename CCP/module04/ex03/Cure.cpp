/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:30:35 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/08 11:01:39 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Created cure materia" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Destroyed cure materia" << std::endl;
}

Cure::Cure(Cure &other): AMateria("cure")
{
	std::cout << "Created cure materia" << std::endl;
	type = other.type;
}

Cure &Cure::operator=(Cure &other)
{
	type = other.type;
	return *this;
}

AMateria *Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals "
		<< target.getName() << "'s wounds *" << std::endl;
}
