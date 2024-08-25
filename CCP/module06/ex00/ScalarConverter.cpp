/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:30:17 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/12 13:55:03 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include <iomanip>
void	convert_double(double a)
{
	std::cout << "char: ";
	if (a <= CHAR_MAX && a >= CHAR_MIN)
	{
		char temp = (char)a;
		if (isprint(temp))
			std::cout << "'" << static_cast<char>(a) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (a <= INT_MAX && a >= INT_MIN)
		std::cout << static_cast<int>(a) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: ";
	if ((a <= std::numeric_limits<float>::max() && a >= -std::numeric_limits<float>::max()) || a == 0)
		std::cout << std::setprecision(std::numeric_limits<float>::digits10)
			<< static_cast<float>(a) << "f" <<std::endl;
	else if (a != a)
		std::cout << "nanf" << std::endl;
	else if (a == INFINITY)
		std::cout << "+inff" << std::endl;
	else if (a == -INFINITY)
		std::cout << "-inff" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "double: ";
	std::cout << std::setprecision(std::numeric_limits<double>::digits10)
		<< static_cast<double>(a) << std::endl;
}


void ScalarConverter::convert(std::string str)
{
	bool invalid = str.empty();

	if (str == "+inff" || str == "+inf")
		convert_double(std::numeric_limits<double>::infinity());
	else if (str == "-inff" || str == "-inf")
		convert_double(-std::numeric_limits<double>::infinity());
	else if (str == "nan")
		convert_double(NAN);
	else if (str.length() == 1 && !std::isdigit(str[0]))
		convert_double(static_cast<double>(str[0]));
	else
	{
		try
		{convert_double(std::stod(str));}
		catch (const std::exception& e)
		{invalid = 1;}
	}
	if (!invalid)
		return ;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
