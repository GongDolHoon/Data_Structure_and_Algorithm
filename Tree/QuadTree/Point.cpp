#include "Point.h"

Point::Point(const int32_t x, const int32_t y)
	: mX(x)
	, mY(y)
{	
}

Point::Point(const Point& other)
	: mX(other.mX)
	, mY(other.mY)
{
}

