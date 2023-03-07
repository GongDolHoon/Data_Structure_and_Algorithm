#include "Quadrant.h"

#include "BoundingRect.h"
#include "GameObject.h"
#include "Point.h"

Quadrant::Quadrant(BoundingRect* const boundingRect)
	: mBoundingRect(boundingRect)
{
	CreateChildren();
}

Quadrant::~Quadrant()
{
	delete mTopLeft;
	mTopLeft = nullptr;
	delete mTopRight;
	mTopRight = nullptr;
	delete mBottomLeft;
	mBottomLeft = nullptr;
	delete mBottomRight;
	mBottomRight = nullptr;
	
	mGameObjects.clear();
}

void Quadrant::CreateChildren()
{
	const int width = mBoundingRect->GetWidth();
	const int height = mBoundingRect->GetHeight();
	
	if(width < 2 * MIN_QUAD_DIMENSION || height < 2 * MIN_QUAD_DIMENSION)
	{
		return;
	}
	
	int x1 = mBoundingRect->GetTopLeft()->GetX();
	int y1 = mBoundingRect->GetTopLeft()->GetY();
	int x2 = mBoundingRect->GetBottomRight()->GetX();
	int y2 = mBoundingRect->GetBottomRight()->GetY();
	
	int midX = (x1 + x2) / 2;
	int midY = (y1 + y2) / 2;
	
	Point* p1 = new Point(x1, y1);
	Point* p2 = new Point(midX, midY);
	
	BoundingRect* rect = new BoundingRect(p1, p2->GetX() - p1->GetX(), p2->GetY() - p1->GetY());
	
	mTopLeft = new Quadrant(rect);
	
	delete p2;
	
	p1 = new Point(midX, y1);
	p2 = new Point(x2, midY);
	
	rect = new BoundingRect(p1, p2->GetX() - p1->GetX(), p2->GetY() - p1->GetY());
	
	mTopRight = new Quadrant(rect);
	
	delete p2;
	
	p1 = new Point(x1, midY);
	p2 = new Point(midX, y2);
	
	rect = new BoundingRect(p1, p2->GetX() - p1->GetX(), p2->GetY() - p1->GetY());
	
	mBottomLeft = new Quadrant(rect);
	
	delete p2;
	
	p1 = new Point(midX, midY);
	p2 = new Point(x2, y2);
	rect = new BoundingRect(p1, p2->GetX() - p1->GetX(), p2->GetY() - p1->GetY());
	
	mBottomRight = new Quadrant(rect);
}

std::vector<GameObject> Quadrant::GetGameObjects(BoundingRect* const rect)
{
	if(!mBoundingRect->IsContain(rect))
	{
		mGameObjects.clear();
		return mGameObjects;
	}
	
	if(mTopLeft == nullptr)
	{
		return mGameObjects;
	}
	
	if(mTopLeft->mBoundingRect->IsContain(rect))
	{
		return mTopLeft->GetGameObjects(rect);
	}
	
	if(mTopRight->mBoundingRect->IsContain(rect))
	{
		return mTopRight->GetGameObjects(rect);
	}
	
	if(mBottomRight->mBoundingRect->IsContain(rect))
	{
		return mBottomRight->GetGameObjects(rect);
	}
	
	if(mBottomRight->mBoundingRect->IsContain(rect))
	{
		return mBottomLeft->GetGameObjects(rect);
	}
	
	return mGameObjects;
}

bool Quadrant::Insert(GameObject* const gameObject)
{
	Point* position = gameObject->GetPosition();
	
	if(!mBoundingRect->IsContain(position))
	{
		return false;
	}
	
	if(mTopLeft != nullptr)
	{
		mTopLeft->Insert(gameObject);
		mTopRight->Insert(gameObject);
		mBottomLeft->Insert(gameObject);
		mBottomRight->Insert(gameObject);
	}
	
	return true;
}
