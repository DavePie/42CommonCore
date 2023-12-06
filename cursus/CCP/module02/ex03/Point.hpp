/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:57:59 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/06 12:34:03 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTHPP
#define POINTHPP
#include "Fixed.hpp"
class Point
{
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point();
	Point(Fixed x, Fixed y);
	Point(const Point &f);
	Point &operator=(const Point &f);
	~Point();
	Fixed x();
	Fixed y();
};
bool bsp(Point t1, Point t2, Point t3, Point p);
#endif