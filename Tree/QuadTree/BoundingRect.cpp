#include "BoundingRect.h"

#include <cassert>

BoundingRect::BoundingRect(Point* const topLeft, const int32_t width, const int32_t height)
	: mTopLeft(topLeft)
{
	assert(width >= 0);
	assert(height >= 0);
	
	mBottomRight = new Point(topLeft->GetX() + width, topLeft->GetY() + height);
}

bool BoundingRect::IsContain(Point* point) const
{
	const int32_t x = point->GetX();
	const int32_t y = point->GetY();
	
	return x >= mTopLeft->GetX()
		&& x <= mBottomRight->GetX()
		&& y >= mTopLeft->GetY()
		&& y <= mBottomRight->GetY();
}

bool BoundingRect::IsContain(BoundingRect* other) const
{
	const int32_t x1 = mTopLeft->GetX();
	const int32_t x2 = mBottomRight->GetX();
	const int32_t y1 = mTopLeft->GetY();
	const int32_t y2 = mBottomRight->GetY();
	
	const int32_t otherX1 = other->mTopLeft->GetX();
	const int32_t otherX2 = other->mBottomRight->GetX();
	const int32_t otherY1 = other->mTopLeft->GetY();
	const int32_t otherY2 = other->mBottomRight->GetY();
	
	return x1 <= otherX1
		&& x2 >= otherX2
		&& y1 <= otherY1
		&& y2 >= otherY2;
}
