/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:39:40 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/04 17:55:43 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}


Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::annonce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed" << std::endl;
}
