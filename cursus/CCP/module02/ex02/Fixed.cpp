/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:15:16 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/06 10:51:26 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	val = 0;
}

Fixed::Fixed(const Fixed &f)
{
	val = f.val;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &f)
{
	val = f.val;
	return *this;
}

int Fixed::getRawBits(void) const
{
	return val;
}

void Fixed::setRawBits(int const raw)
{
	val = raw;
}

Fixed::Fixed(const int input)
{
	val = input << 8;
}


Fixed::Fixed(const float input)
{
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

Fixed Fixed::operator+(const Fixed & f)
{
	Fixed temp;
	temp.setRawBits(val + f.val);
	return temp;
}

Fixed Fixed::operator-(const Fixed & f)
{
	Fixed temp;
	temp.setRawBits(val - f.val);
	return temp;
}

Fixed Fixed::operator*(const Fixed & f)
{
	Fixed temp;
	temp.setRawBits((val * f.val) >> 8);
	return temp;
}

Fixed Fixed::operator/(const Fixed & f)
{
	Fixed temp;
	temp.setRawBits(((val << 8) / (f.val)));
	return temp;
}

Fixed& Fixed::operator++()
{
	++val;
	return *this;
}

Fixed& Fixed::operator--()
{
	--val;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++val;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--val;
	return temp;
}

bool Fixed::operator>(const Fixed & f)
{
	return val > f.val;
}

bool Fixed::operator<(const Fixed & f)
{
	return val < f.val;
}

bool Fixed::operator>=(const Fixed & f)
{
	return val >= f.val;
}

bool Fixed::operator<=(const Fixed & f)
{
	return val <= f.val;
}

bool Fixed::operator==(const Fixed & f)
{
	return val == f.val;
}

bool Fixed::operator!=(const Fixed & f)
{
	return val != f.val;
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	return a <= b ? a : b;
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b)
{
	return a.getRawBits() <= b.getRawBits() ? a : b;
}
Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	return a >= b ? a : b;
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b)
{
	return a.getRawBits() >= b.getRawBits() ? a : b;
}
