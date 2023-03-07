#pragma once

#include <cstdint>
#include <vector>

class Quadrant;
class BoundingRect;
class GameObject;

class Quadrant final 
{
public:
	Quadrant(BoundingRect* const boundingRect);
	Quadrant(const Quadrant& other) = delete;
	Quadrant& operator=(const Quadrant& other) = delete;
	
	~Quadrant();
	
	void CreateChildren();
	std::vector<GameObject> GetGameObjects(BoundingRect* const rect);
	bool Insert(GameObject* const gameObject);
	
private:
	static const int32_t MIN_QUAD_DIMENSION = 2;
	
	const BoundingRect* mBoundingRect;
	
	Quadrant* mTopLeft;
	Quadrant* mTopRight;
	Quadrant* mBottomLeft;
	Quadrant* mBottomRight;
	
	std::vector<GameObject> mGameObjects;
};
