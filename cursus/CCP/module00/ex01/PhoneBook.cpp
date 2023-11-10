/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:20:02 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/10 10:35:32 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}
PhoneBook::~PhoneBook()
{
}
void PhoneBook::add(std::string f, std::string l, std::string n, std::string p, std::string s)
{
	this->phone_book[this->index].set(f, l, n, p, s);
	this->index = (this->index + 1) % 8;
}

Contact PhoneBook::search(int index)
{
	if (index < 1 || index > 8
		|| !this->phone_book[this->index].is_set())
		std::cout << "There is no contact at the index " << index << std::endl;
	return this->phone_book[this->index];
}

void PhoneBook::print_phone_book()
{
	Contact t = this->phone_book[0];
	t.print_element_tab("index");
	t.print_element_tab("first name");
	t.print_element_tab("last name");
	t.print_element_tab("nickname");
	for (int i = 0; i < 8; i++)
	{
		if (!this->phone_book[i].is_set())
			break;
		std::cout << "|" << (i + 1) << "         ";
		this->phone_book[i].print_contact_tab();
		std::cout << std::endl;
	}
}
