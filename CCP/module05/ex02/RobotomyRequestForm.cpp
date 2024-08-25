/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:40:57 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/11 15:09:52 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other): 	AForm("RobotomyRequestForm", 72, 45), _target(other._target)
{}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
	(void) other;
	return *this;
}

void RobotomyRequestForm::action(void) const
{
	std::cout << "Brrrrrr.... brrrrrr...." << std::endl
		<< _target << " has had a ";
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << "successful";
	else
		std::cout << "failed";
	std::cout << " robotomy." << std::endl;
}
