/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:53:09 by marvin            #+#    #+#             */
/*   Updated: 2023/12/05 15:12:11 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "This is the debug level" << std::endl;
}

void Harl::info(void)
{
	std::cout << "This is the info level" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "This is the warning level" << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is the error level" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string level_names[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::* level_funcs[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	Harl h;
	for (int i = 0; i < 4; i++)
	{
		if (level_names[i] == level)
		{
			(h.*level_funcs[i])();
			return;
		}
	}
	std::cout << "Invalid level" << std::endl;
}

void Harl::complain_above(std::string level)
{
	std::string level_names[] = {"DEBUG", "INFO", "WARNING", "ERROR", "UKNOWN"};
	int level_index = 4;
	for (int i = 0; i < 4; i++)
		if (level_names[i] == level)
			level_index = i;
	std::cout << "[" << level_names[level_index] << "]" << std::endl;
	switch(level_index)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
	}
}