/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:53:28 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/04 17:02:20 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *dave = newZombie("zombie2 on heap");
	dave->annonce();
	Zombie *bob = newZombie("zombie1 on heap");
	bob->annonce();
	randomChump("zombie1 on stack");
	randomChump("zombie2 on stack");
	delete bob;
	delete dave;
	return (0);
}