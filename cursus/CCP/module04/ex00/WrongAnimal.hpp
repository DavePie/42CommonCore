/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:38:13 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/07 15:24:21 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMALHPP
# define WRONGANIMALHPP
#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal& other);
		WrongAnimal& operator=(WrongAnimal & other);
		virtual ~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
};

#endif