/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:56:46 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/06 17:57:38 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAPHPP
# define SCAVTRAPHPP
#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
	public:
		ScavTrap(std::string name);
		void guardGate();
		void attack(const std::string &target);
		~ScavTrap();
		ScavTrap(ScavTrap &other);
};
#endif