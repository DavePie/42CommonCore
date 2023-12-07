#include "Character.hpp"

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::~Character()
{
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
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <=3)
		inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <=3 && inventory[idx] != NULL)
		inventory[idx]->use(target);
}
