#pragma once

#include <cstdint>
#include <cmath>
#include "Point.h"

class BoundingRect final
{
public:
	BoundingRect(Point* const topLeft, const int32_t width, const int32_t height);
	BoundingRect(const BoundingRect& other) = delete;
	BoundingRect& operator=(const BoundingRect& other) = delete;
	
	~BoundingRect() = default;
	
	bool IsContain(Point* point) const;
	bool IsContain(BoundingRect* other) const;
		
	inline const Point* GetBottomRight() const
	{
		return mBottomRight;
	}
	
	inline int32_t GetHeight() const
	{
		const int32_t y1 = mTopLeft->GetY();
		const int32_t y2 = mBottomRight->GetY();
		
		return abs(y1 - y2);
	}
	
	inline const Point* GetTopLeft() const
	{
		return mTopLeft;
	}
	
	inline int32_t GetWidth() const
	{
		const int32_t x1 = mTopLeft->GetX();
		const int32_t x2 = mBottomRight->GetX();
		
		return abs(x1 - x2);
	}

	
private:
	const Point* mTopLeft;
	const Point* mBottomRight;
};
