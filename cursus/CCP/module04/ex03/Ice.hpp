/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:43:18 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 16:51:10 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICEHPP
# define ICEHPP
# include "AMateria.hpp"
class Ice: public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(Ice &other);
		Ice& operator=(Ice& other);
		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif