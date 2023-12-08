/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:34:25 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 18:41:24 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIAHPP
# define AMATERIAHPP
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
		AMateria();
	public:
		AMateria(std::string const & type);
		AMateria(AMateria & other);
		AMateria & operator=(AMateria &other);
		virtual ~AMateria();
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif