/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:05:22 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/10 17:49:24 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <iostream>
class AForm;
# include "Bureaucrat.hpp"

class AForm
{
private:
	std::string const	_name;
	int const			_grade_sign;
	int const			_grade_exec;
	bool				_signed;
	void verify_grade();

public:
	AForm(std::string const &name, const int grade_sign, const int grade_exec);
	virtual ~AForm();
	AForm(AForm const &other);
	AForm &operator=(AForm const &other);
	
	std::string const &getName(void) const;
	int getGradeSign(void) const;
	int getGradeExec(void) const;
	bool getSigned(void) const;
	virtual void action(void) const = 0;
	void execute(Bureaucrat const & executor) const;
	class GradeTooHighException : public std::exception {
		const char * what () const throw();
	};
	class GradeTooLowException : public std::exception {
		const char * what () const throw();
	};
	class FormNotSignedException : public std::exception {
		const char * what () const throw();
	};
	void beSigned(Bureaucrat const &b);
};

std::ostream& operator << (std::ostream &out, const AForm &c);

#endif