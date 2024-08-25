#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name)
{
	std::cout << "Created character " << name << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "Deleted character " << name << std::endl;
	for (int i = 0; i < 4; i++)
		if (inventory[i] != NULL)
			delete inventory[i];
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << "Equipped materia " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "Inventory full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && inventory[idx] != NULL)
	{
		std::cout << "Unequipped inventory slot " << idx << " of materia "
			<< inventory[idx]->getType() << std::endl;
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <=3 && inventory[idx] != NULL)
		inventory[idx]->use(target);
	else
		std::cout << "No valid materia at slot " << idx << std::endl;
}

Character::Character(Character & other)
{
	name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] == NULL)
			inventory[i] = NULL;
		else
			inventory[i] = other.inventory[i]->clone();
	}
}

Character &Character::operator=(Character &other)
{
	name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] == NULL)
			inventory[i] = NULL;
		else
			inventory[i] = other.inventory[i]->clone();
	}
	return *this;
}
