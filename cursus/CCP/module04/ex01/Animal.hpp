/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:38:13 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 16:24:13 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMALHPP
# define ANIMALHPP
#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal& other);
		Animal& operator=(Animal & other);
		virtual ~Animal();
		virtual void makeSound() const;
		virtual std::string getType() const;
};

#endif