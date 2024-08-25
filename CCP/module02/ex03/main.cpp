/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:13:09 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/06 12:50:51 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	std::cout << "Not in triangle: " <<
		bsp(Point(Fixed(0), Fixed(10)), Point(Fixed(10), Fixed(0)), Point(Fixed(10), Fixed(10)), Point(Fixed(0), Fixed(0))) << std::endl;
	std::cout<< "Not in triangle (edge): " <<
		bsp(Point(Fixed(0), Fixed(10)), Point(Fixed(10), Fixed(0)), Point(Fixed(10), Fixed(10)), Point(Fixed(5), Fixed(5))) << std::endl;
	std::cout << "Not in triangle (edge): " <<
		bsp(Point(Fixed(0), Fixed(0)), Point(Fixed(10), Fixed(0)), Point(Fixed(10), Fixed(10)), Point(Fixed(5), Fixed(5))) << std::endl;
	std::cout << "Not in triangle: " <<
		bsp(Point(Fixed(0), Fixed(10)), Point(Fixed(10), Fixed(0)), Point(Fixed(10), Fixed(10)), Point(Fixed(20), Fixed(20))) << std::endl;
	std::cout << "In triangle: " <<
		bsp(Point(Fixed(0), Fixed(0)), Point(Fixed(0), Fixed(10)), Point(Fixed(10), Fixed(0)), Point(Fixed(1), Fixed(1))) << std::endl;
	std::cout << "Not in triangle (vertex): " <<
		bsp(Point(Fixed(0), Fixed(0)), Point(Fixed(0), Fixed(10)), Point(Fixed(10), Fixed(0)), Point(Fixed(0), Fixed(0))) << std::endl;
	std::cout << "In triangle " <<
		bsp(Point(Fixed(10), Fixed(10)), Point(Fixed(0), Fixed(10)), Point(Fixed(10), Fixed(0)), Point(Fixed(7), Fixed(7))) << std::endl;
	return 0;
}