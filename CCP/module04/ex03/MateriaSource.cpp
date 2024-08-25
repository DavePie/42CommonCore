/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:20:36 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/08 11:07:54 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Created MateriaSource" << std::endl;
	for (int i = 0; i < 4; i++)
		templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &other)
{
	std::cout << "Created MateriaSource" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.templates[i] == NULL)
			templates[i] = NULL;
		else
			templates[i] = other.templates[i]->clone();
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.templates[i] == NULL)
			templates[i] = NULL;
		else
			templates[i] = other.templates[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Deleted MateriaSource" << std::endl;
	for (int i = 0; i < 4; i++)
		if (templates[i] != NULL)
			delete templates[i];
}

void MateriaSource::learnMateria(AMateria * materia)
{
	for (int i = 0; i < 4; i++)
		if (templates[i] == NULL)
		{
			templates[i] = materia;
			std::cout << "Added " << materia->getType() << " to slot " << i << std::endl;
			return ;
		}
	std::cout << "All materia slots full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (templates[i] != NULL 
			&& templates[i]->getType() == type)
		return templates[i]->clone();
	std::cout << "Unable to find materia of type: " << type << std::endl;
	return NULL;
}