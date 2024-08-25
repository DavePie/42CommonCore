/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:05:19 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/10 17:44:53 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade too low.";
}

void Form::verify_grade()
{
	if (_grade_sign < 1 || _grade_exec < 1)
		throw GradeTooHighException();
	if (_grade_exec > 150 || _grade_exec > 150)
		throw GradeTooLowException();
}

Form::Form(std::string const & name, const int grade_sign, const int grade_exec):
	_name(name), _grade_sign(grade_sign), _grade_exec(grade_exec), _signed(false)
{
	verify_grade();
}

Form::~Form()
{
}

Form::Form(Form const & other):
	_name(other._name), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec),
	_signed(other._signed)
{
	verify_grade();
}

Form & Form::operator=(Form const & other)
{
	_signed = other._signed;
	return *this;
}

std::string const & Form::getName(void) const
{
	return _name;
}

int Form::getGradeSign(void) const
{
	return _grade_sign;
}

int Form::getGradeExec(void) const
{
	return _grade_exec;
}

bool Form::getSigned(void) const
{
	return _signed;
}

void Form::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() > _grade_sign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream & operator<<(std::ostream & out, const Form & c)
{
	out << c.getName() << ", form grades sign " << c.getGradeSign()
		<< " execute " << c.getGradeExec() << " signed status " << c.getSigned() <<"." << std::endl;
	return (out);
}
