/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:20:02 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/01 15:41:58 by dvandenb         ###   ########.fr       */
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

bool PhoneBook::is_set(int index)
{
	return (index >= 1 && index <= 8 && this->phone_book[index - 1].is_set());
}

Contact PhoneBook::search(int index)
{
	return this->phone_book[index - 1];
}

void PhoneBook::print_phone_book()
{
	Contact t = this->phone_book[0];

	if (!t.is_set())
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}
	std::cout << "     index";
	t.print_element_tab("first name");
	t.print_element_tab("last name");
	t.print_element_tab("nickname");
	for (int i = 0; i < 8; i++)
	{
		if (!this->phone_book[i].is_set())
			break;
		std::cout << std::endl << "         " << (i + 1);
		this->phone_book[i].print_contact_tab();
	}
	std::cout << std::endl;
}
