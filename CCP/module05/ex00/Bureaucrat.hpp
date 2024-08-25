/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:07:31 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/10 17:10:56 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
	void verify_grade();

public:
	Bureaucrat(std::string const &name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	
	std::string const &getName(void) const;
	int getGrade(void) const;

	Bureaucrat& operator++();
	Bureaucrat& operator--();
	
	class GradeTooHighException : public std::exception {
		const char * what () const throw();
	};
	class GradeTooLowException : public std::exception {
		const char * what () const throw();
	};
};

std::ostream& operator << (std::ostream &out, const Bureaucrat &c);

#endif