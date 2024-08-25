/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:14:02 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/04 17:55:21 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>
class Zombie {
	private:
		std::string name;

	public:
		Zombie(std::string name);
		void annonce(void);
		~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif