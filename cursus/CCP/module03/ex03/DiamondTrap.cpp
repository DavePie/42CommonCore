/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:14:21 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 11:47:30 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->attack_dmg = 30;
	std::cout << "DiamondTrap " << name << " was created!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " was destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap & other): ClapTrap(other.name + "_clap_name"), FragTrap(other.name), ScavTrap(other.name)
{
	this->name = other.name;
	this->attack_dmg = 30;
	std::cout << "DiamondTrap " << name << " was created!" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap & other)
{
	this->name = other.name;
	this->attack_dmg = other.attack_dmg;
	this->ClapTrap::name = other.ClapTrap::name;
	this->energy_pts = other.energy_pts;
	this->hit_pts = other.hit_pts;
	return *this;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " + name
		+ " though my close friends call me " + this->ClapTrap::name << std::endl;
}

