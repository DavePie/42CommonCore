/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:38:13 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 12:45:21 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CATHPP
# define CATHPP
# include "Animal.hpp"

class Cat : public Animal
{
	protected:
		std::string type;
	public:
		Cat();
		Cat(Cat& other);
		Cat& operator=(Cat & other);
		~Cat();
		void makeSound() const;
		std::string getType() const;
};

#endif