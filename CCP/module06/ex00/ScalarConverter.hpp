/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:02:22 by dvandenb          #+#    #+#             */
/*   Updated: 2024/01/12 13:43:20 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter(){};
	public:
		~ScalarConverter(){};
		ScalarConverter(ScalarConverter const &other){(void)other;};
		ScalarConverter &operator=(ScalarConverter const &other){(void)other; return *this;};
		static void convert(std::string str);
};

#endif