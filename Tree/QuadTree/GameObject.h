#pragma once

#include <cstdint>
#include "Point.h"

class GameObject final 
{
public:
	GameObject(Point* const position, const int32_t data)
		: mPosition(position)
		, mData(data)
	{
	}
	
	GameObject(const GameObject& other) = delete;
	GameObject& operator=(const GameObject& other) = delete;
	
	~GameObject() = default;
	
	inline int32_t GetData()
	{
		return mData;
	}
	
	inline Point* GetPosition()
	{
		return mPosition;
	}
	
private:
	Point* mPosition;
	int32_t mData;
};
