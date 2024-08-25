/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:06:15 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/10 17:34:58 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	verify_grade();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other): _name(other._name), _grade(other._grade)
{
	verify_grade();
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other)
{
	_grade = other._grade;
	return *this;
}

std::string const & Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

Bureaucrat & Bureaucrat::operator++()
{
	++_grade;
	verify_grade();
	return *this;
}

Bureaucrat & Bureaucrat::operator--()
{
	--_grade;
	verify_grade();
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureacrat grade too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureacrat grade too low.";
}

void Bureaucrat::verify_grade()
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c)
{
	out << c.getName() << ", bureaucrat grade " << c.getGrade() << "." << std::endl;
	return out;
}

