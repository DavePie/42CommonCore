/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:10:31 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/01 15:42:30 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string cin_nonempty(std::string prompt)
{
	std::string input = "";

	std::cout << prompt;
	while (!(std::cin >> input) || input.length() == 0)
	{
		std::cout << "This field can not be empty" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	return input;
}

void add_phonebook(PhoneBook &pb)
{
	pb.add(
		cin_nonempty("First name: "), cin_nonempty("Last name: "),
		cin_nonempty("Nickname: "), cin_nonempty("Phone number: "),
		cin_nonempty("Darkest secret: "));
}

void find_contact(PhoneBook &pb)
{
	int index;
	bool visited = false;
	index = -1;

	if (!pb.is_set(1))
		return;
	std::cout << "Please input a index: ";
	while (!pb.is_set(index))
	{
		if (visited)
			std::cout << "Please enter a valid index: ";
		while (!(std::cin >> index))
		{
			std::cout << "Please enter a number: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		visited = true;
	}
	pb.search(index).print_contact();
}

int main(void)
{
	std::string input = "";
	std::cout << "Welcome to Ph0n3600k 2.23" << std::endl;
	PhoneBook pb = PhoneBook();
	while (true)
	{
		std::cout << "Options: ADD, SEARCH, EXIT" << std::endl;
		std::cin >> input;
		if (!input.compare("ADD"))
		{
			add_phonebook(pb);
		}
		else if (!input.compare("SEARCH"))
		{
			pb.print_phone_book();
			find_contact(pb);
		}
		else if (!input.compare("EXIT"))
		{
			std::cout << "Bye!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid input" << std::endl;
	}
}
