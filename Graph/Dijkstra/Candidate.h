#pragma once

#include <cstdint>

#include "Node.h"

class Candidate final
{
public:
	Candidate(Node* node, uint32_t distance)
		: mNode(node)
		, mDistance(distance)
	{
	}

	Candidate(const Candidate& other) = delete;
	Candidate& operator=(const Candidate& other) = delete;

	~Candidate() = default;

	inline Node* GetNode() const
	{
		return mNode;
	}

	inline uint32_t GetDistance() const
	{
		return mDistance;
	}

	inline int32_t operator-(const Candidate& other) const
	{
		return mDistance - other.mDistance;
	}

private:
	Node* mNode;
	uint32_t mDistance;
};