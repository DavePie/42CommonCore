/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:14:26 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/06 17:16:01 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAPHPP
# define CLAPTRAPHPP
# include <string>
# include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		int			hit_pts;
		int			energy_pts;
		int			attack_dmg;
		ClapTrap();
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(ClapTrap& other);
		ClapTrap& operator=(ClapTrap& other);
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
#endif