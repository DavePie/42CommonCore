/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:05:22 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/10 17:49:24 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
class Form;
# include "Bureaucrat.hpp"

class Form
{
private:
	std::string const	_name;
	int const			_grade_sign;
	int const			_grade_exec;
	bool				_signed;
	void verify_grade();

public:
	Form(std::string const &name, const int grade_sign, const int grade_exec);
	~Form();
	Form(Form const &other);
	Form &operator=(Form const &other);
	
	std::string const &getName(void) const;
	int getGradeSign(void) const;
	int getGradeExec(void) const;
	bool getSigned(void) const;
	class GradeTooHighException : public std::exception {
		const char * what () const throw();
	};
	class GradeTooLowException : public std::exception {
		const char * what () const throw();
	};
	void beSigned(Bureaucrat const &b);
};

std::ostream& operator << (std::ostream &out, const Form &c);

#endif