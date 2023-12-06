/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:37:39 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/06 15:10:21 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap bob("bob");
	bob.attack("god");
	bob.guardGate();
	FragTrap fred("fred");
	fred.highFivesGuys();
	return (0);
}