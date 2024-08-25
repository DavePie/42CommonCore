/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:38:13 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 12:45:21 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOGHPP
# define DOGHPP
# include "Animal.hpp"

class Dog : public Animal
{
	protected:
		std::string type;
	public:
		Dog();
		Dog(Dog& other);
		Dog& operator=(Dog & other);
		~Dog();
		void makeSound() const;
		std::string getType() const;
};

#endif