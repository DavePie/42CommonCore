/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:01:11 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/05 18:57:14 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXEDHPP
# define FIXEDHPP
# include <iostream>
# include <cmath>
class Fixed
{
	private:
		int val;
		static const int nbits = 8;
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed(const int input);
		Fixed(const float intput);
		~Fixed();
		Fixed& operator=(const Fixed &f);
		bool operator>(const Fixed &f);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		
};
std::ostream& operator << (std::ostream &out, const Fixed &c);

#endif