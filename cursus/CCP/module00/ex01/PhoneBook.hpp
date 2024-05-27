/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:13:14 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/01 14:56:58 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
#include <string>
#include <sstream>

class PhoneBook
{
	private:
		Contact	phone_book[8];
		int		index;
	public:
		PhoneBook();
		~PhoneBook();
		void	add(std::string, std::string, std::string, std::string, std::string);
		Contact	search(int index);
		bool	is_set(int index);
		void	print_phone_book();
};
#endif