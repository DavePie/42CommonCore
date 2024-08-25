/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:43:18 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 17:29:48 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUREHPP
# define CUREHPP
# include "AMateria.hpp"
class Cure: public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(Cure &other);
		Cure& operator=(Cure& other);
		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif