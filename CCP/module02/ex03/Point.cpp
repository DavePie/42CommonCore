#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {}

Point::Point(const Point &f) : _x(f._x), _y(f._y) {}

Point &Point::operator=(const Point &f)
{
	(Fixed) _x = f._x;
	(Fixed) _y = f._y;
	return *this;
}

Point::~Point() {}

Fixed Point::x()
{
	return _x;
}

Fixed Point::y()
{
	return _y;
}