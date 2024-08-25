/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:27:13 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/08 11:07:39 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria* ice = new Ice();
	src->learnMateria(ice);
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(-1, *bob);
	me->use(5, *bob);
	me->use(-1, *bob);
	me->equip(ice);
	me->use(2, *bob);
	me->unequip(2);
	me->unequip(2);
	me->use(2, *bob);
	Character fred("fred");
	fred.equip(src->createMateria("ice"));
	Character john = fred;
	john.use(0, *me);
	delete ice;
	delete bob;
	delete me;
	delete src;
	//delete fred;
	return 0;
}