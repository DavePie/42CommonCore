/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:03:02 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 11:48:39 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAPHPP
# define FRAGTRAPHPP
#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
	public:
		FragTrap(std::string name);
		void highFivesGuys(void);
		~FragTrap();
		FragTrap(FragTrap &other);
		FragTrap& operator=(FragTrap& other);
};
#endif