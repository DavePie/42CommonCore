/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:38:45 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/05 16:53:39 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>
class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		const std::string getType(void);
		void setType(std::string type);
};
#endif