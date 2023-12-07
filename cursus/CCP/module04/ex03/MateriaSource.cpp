/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:20:36 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 18:26:43 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		templates[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (templates[i] != NULL)
			delete templates[i];
}

void MateriaSource::learnMateria(AMateria * materia)
{
	for (int i = 0; i < 4; i++)
		if (templates[i] == NULL)
			templates[i] = materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (templates[i] != NULL 
			&& templates[i]->getType() == type)
		return templates[i]->clone();
	return NULL;
}