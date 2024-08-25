/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:47:52 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/11 13:49:26 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern i = Intern();
	Bureaucrat b = Bureaucrat("John", 20);
	AForm *f = i.makeForm("robotomy request", "everyone");
	AForm *f2 = i.makeForm("shrubbery creation", "the ground");
	AForm *f3 = i.makeForm("does not exist", "whatever");
	std::cout << "This should be null: " << f3 << std::endl;
	b.signForm(*f);
	b.executeForm(*f);
	b.signForm(*f2);
	b.executeForm(*f2);
	delete f, delete f2;
}