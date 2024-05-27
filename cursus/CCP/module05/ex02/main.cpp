/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:47:52 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/11 15:06:22 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	AForm *test =  new ShrubberyCreationForm("bob");
	AForm *test2 =  new RobotomyRequestForm("dog");
	AForm *test3 =  new PresidentialPardonForm("god");
	Bureaucrat b = Bureaucrat("freddy", 75);
	Bureaucrat a = Bureaucrat("argh", 10);
	Bureaucrat aa = Bureaucrat("zzzzz", 1);

	b.executeForm(*test);
	b.signForm(*test);
	b.executeForm(*test);
	b.executeForm(*test2);
	a.executeForm(*test3);
	a.signForm(*test);
	a.signForm(*test3);
	a.executeForm(*test3);
	aa.executeForm(*test3);
	
	delete test, delete test2, delete test3;
}