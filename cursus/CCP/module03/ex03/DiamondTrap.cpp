/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:14:21 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/06 17:59:56 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	
	this->name = name;
	this->attack_dmg = 30;
}


void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " + name
		+ " though my close friends call me " + this->ClapTrap::name << std::endl;
}

