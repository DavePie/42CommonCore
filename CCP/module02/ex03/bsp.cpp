/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvandenb <dvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:14:19 by dvandenb          #+#    #+#             */
/*   Updated: 2023/12/06 12:37:33 by dvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed side(Point p, Point s1, Point s2)
{
	return (p.x() - s2.x()) * (s1.y() - s2.y()) - (s1.x() - s2.x()) * (p.y() - s2.y());
}

bool bsp(Point t1, Point t2, Point t3, Point p)
{
	Fixed side1 = side(p, t1, t2);
	Fixed side2 = side(p, t2, t3);
	Fixed side3 = side(p, t3, t1);
	bool any_negative = side1 <= Fixed(0) || side2 <= Fixed(0) || side3 <= Fixed(0);
	bool any_positive = side1 >= Fixed(0) || side2 >= Fixed(0) || side3 >= Fixed(0);
	return !(any_negative && any_positive);
}