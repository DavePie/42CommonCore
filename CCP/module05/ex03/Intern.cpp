/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:24:32 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/11 14:54:11 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}
Intern::~Intern()
{}
Intern::Intern(Intern const &other)
{
	(void)other;
}
Intern & Intern::operator=(Intern const &other)
{
	(void)other;
	return *this;
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm * (* funcs [3])(std::string) = {PresidentialPardonForm::generate, RobotomyRequestForm::generate, ShrubberyCreationForm::generate};

	for (int i = 0; i < 3; i++) {
		if (form == names[i]) {
			std::cout << "Intern creates " << form << " form" << std::endl;
			return funcs[i](target);
		}
	}
	std::cout << "Intern was unable to find the " << form << " form" << std::endl;
	return 0;
}
