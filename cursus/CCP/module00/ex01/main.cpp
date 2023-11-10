/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:10:31 by dvandenb          #+#    #+#             */
/*   Updated: 2023/11/10 10:43:33 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string cin_nonempty(std::string prompt)
{
	std::string input = "";
	while (!input.length())
	{
		std::cout << prompt;
		std::cin >> input;
	}
	return input;
}

void	add_phonebook(PhoneBook& pb)
{
	pb.add(
	cin_nonempty("First name: "), cin_nonempty("Last name: "),
	cin_nonempty("Nickname: "), cin_nonempty("Phone number: "),
	cin_nonempty("Darkest secret: "));
	std::cout << "Added user" << std::endl;
}

int main()
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
		} else if (!input.compare("SEARCH"))
		{
				std::cout << "this ran3" << std::endl;
		} else if (!input.compare("EXIT"))
		{
			std::cout << "Bye!" << std::endl;
			break;
		} else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << "Options: ADD, SEARCH, EXIT" << std::endl;
		}
	}
}
