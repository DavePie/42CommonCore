/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:01:11 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/05 18:31:15 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXEDHPP
# define FIXEDHPP
# include <iostream>
class Fixed
{
	private:
		int val;
		static const int nbits = 8;
	public:
		Fixed();
		Fixed(const Fixed &f);
		~Fixed();
		Fixed& operator=(const Fixed &f);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
#endif