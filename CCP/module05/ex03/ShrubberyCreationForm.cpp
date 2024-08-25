/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:40:57 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/11 14:51:59 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other): 	AForm("ShrubberyCreationForm", 145, 137), _target(other._target)
{}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other)
{
	(void) other;
	return *this;
}

void ShrubberyCreationForm::action(void) const
{
	std::ofstream fileTree(_target + "_shrubbery");
	if (fileTree.fail())
	{
		std::cout << "Unable to open file" << std::endl;
		return;
	}
	for (int i = 0; i < 10000; i++)
		fileTree <<
			"       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n";
	fileTree.close();
}

AForm * ShrubberyCreationForm::generate(std::string target)
{
	return new ShrubberyCreationForm(target);
}
