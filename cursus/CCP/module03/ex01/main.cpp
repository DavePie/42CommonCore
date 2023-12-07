/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:39 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 11:29:24 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap bob("bob");
	bob.attack("god");
	bob.attack("god");
	bob.attack("god");
	bob.attack("god");
	bob.attack("god");
	bob.attack("god");
	bob.beRepaired(3);
	bob.takeDamage(10);
	bob.guardGate();
	return (0);
}