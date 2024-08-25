/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:39 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/06 13:44:53 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap bob("bob");
	bob.attack("god");
	bob.attack("god");
	bob.attack("god");
	bob.attack("god");
	bob.attack("god");
	bob.attack("god");
	bob.attack("god");
	bob.attack("god");
	bob.attack("god");
	
	bob.takeDamage(2);
	bob.beRepaired(1);
	bob.attack("god");
	bob.takeDamage(9);
	bob.beRepaired(10);
	return (0);
}