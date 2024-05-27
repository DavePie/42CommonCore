/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:47:52 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/10 17:44:38 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	
	Bureaucrat bob = Bureaucrat("bob", 2);
	Form form = Form("the hard law", 1, 10);
	Form form2 = Form("the easier law", 3, 10);
	std::cout << form << std::endl;
	bob.signForm(form);
	bob.signForm(form2);
	try {Form formFail = Form("" , 0, 150);}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {Form formFail = Form("" , 1, 151);}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
}