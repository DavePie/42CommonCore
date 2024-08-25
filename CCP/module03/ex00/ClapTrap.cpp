/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:44 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/06 17:16:34 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hit_pts = 10;
	energy_pts = 10;
	attack_dmg = 0;
	std::cout << "ClapTrap " << name << " was created!" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has died!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	name = other.name;
	hit_pts = other.hit_pts;
	energy_pts = other.energy_pts;
	attack_dmg = other.attack_dmg;
	std::cout << "ClapTrap " << name << " was created!" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &other)
{
	name = other.name;
	hit_pts = other.hit_pts;
	energy_pts = other.energy_pts;
	attack_dmg = other.attack_dmg;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (hit_pts <= 0 || energy_pts <= 0)
	{
		std::cout << "ClapTrap " << name << " is unable to attack!" << std::endl;
		return ;
	}
	energy_pts--;
	std::cout << "ClapTrap " << name << " attacks " << target
		<< ", causing " << attack_dmg << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " has taken " << amount
		<< " points of damage!" << std::endl;
	hit_pts -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_pts <= 0 || energy_pts <= 0)
	{
		std::cout << "ClapTrap " << name
			<< " is unable to repair itself!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " has repaired itself for " << amount
		<< " points of health!" << std::endl;
	hit_pts += amount;
	energy_pts--;
}

