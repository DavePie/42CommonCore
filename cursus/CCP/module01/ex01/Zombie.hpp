/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:14:02 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/04 17:55:30 by dvandenb         ###   ########.fr       */
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
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void annonce(void);
		void setname(std::string name);
};

 Zombie* zombieHorde(int N, std::string name);
#endif