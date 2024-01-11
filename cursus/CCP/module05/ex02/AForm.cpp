/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:05:19 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/11 13:53:25 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade too low.";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "form not signed.";
}

void AForm::verify_grade()
{
	if (_grade_sign < 1 || _grade_exec < 1)
		throw GradeTooHighException();
	if (_grade_exec > 150 || _grade_exec > 150)
		throw GradeTooLowException();
}

AForm::AForm(std::string const & name, const int grade_sign, const int grade_exec):
	_name(name), _grade_sign(grade_sign), _grade_exec(grade_exec), _signed(false)
{
	verify_grade();
}

AForm::~AForm()
{
}

AForm::AForm(AForm const & other):
	_name(other._name), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec),
	_signed(other._signed)
{
	verify_grade();
}

AForm & AForm::operator=(AForm const & other)
{
	_signed = other._signed;
	return *this;
}

std::string const & AForm::getName(void) const
{
	return _name;
}

int AForm::getGradeSign(void) const
{
	return _grade_sign;
}

int AForm::getGradeExec(void) const
{
	return _grade_exec;
}

bool AForm::getSigned(void) const
{
	return _signed;
}

void AForm::action(void) const
{
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _grade_exec)
		throw GradeTooLowException();
	else if (!_signed)
		throw FormNotSignedException();
	else
		action();
}

void AForm::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() > _grade_sign)
		throw GradeTooLowException();
	else
		_signed = true;
}

std::ostream & operator<<(std::ostream & out, const AForm & c)
{
	out << c.getName() << ", AForm grades sign " << c.getGradeSign()
		<< " execute " << c.getGradeExec() << " signed status " << c.getSigned() <<"." << std::endl;
	return (out);
}
