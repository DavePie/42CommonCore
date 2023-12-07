/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:31:25 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 18:43:46 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTERCPP
# define CHARACTERCPP
# include "ICharacter.hpp"
class Character : public ICharacter
{
	protected:
		std::string name;
		AMateria *inventory[4];
		
	public:
		Character(std::string name);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};
#endif

