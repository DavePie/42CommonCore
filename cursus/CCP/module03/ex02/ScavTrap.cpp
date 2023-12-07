/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:03:11 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 11:44:53 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in gate keeper mode" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_pts = 100;
	this->energy_pts = 50;
	this->attack_dmg = 20;
	std::cout << "ScavTrap " << name << " was created!" << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has died!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other.name)
{
	hit_pts = other.hit_pts;
	energy_pts = other.energy_pts;
	attack_dmg = other.attack_dmg;
	std::cout << "ScavTrap " << name << " was created!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (hit_pts <= 0 || energy_pts <= 0)
	{
		std::cout << "ScavTrap " << name << " is unable to attack!" << std::endl;
		return ;
	}
	energy_pts--;
	std::cout << "ScavTrap " << name << " attacks " << target
		<< ", causing " << attack_dmg << " points of damage!" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &other)
{
	name = other.name;
	hit_pts = other.hit_pts;
	energy_pts = other.energy_pts;
	attack_dmg = other.attack_dmg;
	return *this;
}
