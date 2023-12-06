/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:15:16 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/06 10:22:29 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	val = 0;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	val = f.val;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	val = f.val;
	return *this;
}

int Fixed::getRawBits(void) const
{
	return val;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	val = raw;
}

Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called" << std::endl;
	val = input << 8;
}


Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called" << std::endl;
	val = (int)std::roundf(input * 256);
}

float Fixed::toFloat(void) const
{
	return (float)val / 256;
}

int Fixed::toInt(void) const
{
	return val >> 8;
}

std::ostream & operator<<(std::ostream & out, const Fixed & c)
{
	out << c.toFloat();
	return out;
}
