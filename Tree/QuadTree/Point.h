#pragma once

#include <cstdint>

class Point final
{
public:
	Point(const int32_t x, const int32_t y);
	Point(const Point& other);
	Point& operator=(const Point& other)
	{
		mX = other.mX;
		mY = other.mY;
		
		return *this;
	}
	
	~Point();
	
	inline int32_t GetX() const
	{
		return mX;
	}
	inline int32_t GetY() const
	{
		return mY;
	}
	
private:
	int32_t mX;
	int32_t mY;
};
