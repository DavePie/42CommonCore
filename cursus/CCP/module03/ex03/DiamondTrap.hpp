/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:24:30 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 11:34:27 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAPHPP
# define DIAMONDTRAPHPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string name;
		DiamondTrap();
	public:
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(DiamondTrap &other);
		DiamondTrap& operator=(DiamondTrap &other);
		void whoAmI(void);
};
#endif
