/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:04:33 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/06 17:17:39 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_pts = 100;
	this->energy_pts = 50;
	this->attack_dmg = 20;
	std::cout << "FragTrap " << name << " was created!" << std::endl;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has died!" << std::endl;
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other.name)
{
	hit_pts = other.hit_pts;
	energy_pts = other.energy_pts;
	attack_dmg = other.attack_dmg;
	std::cout << "FragTrap " << name << " was created!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " positively requests a high five!" << std::endl;
}

