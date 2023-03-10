#pragma once

#include <cstdint>
#include <unordered_map>

class Node final 
{
public:
	Node(const char* name)
		: mName(name)
	{
	}

	Node(const Node& other) = delete;
	Node& operator=(const Node& other) = delete;

	~Node() = default;

	inline const char* GetName() const
	{
		return mName;
	}

	inline std::unordered_map<Node*, uint32_t> GetRoads() const
	{
		return mRoads;
	}

	inline void AddRoad(Node* to, uint32_t dist)
	{
		mRoads.insert({to, dist});
	}

	inline uint32_t GetDistance(Node* to) const
	{
		return mRoads.at(to);
	}
	 
private:
	const char* mName;
	std::unordered_map<Node*, uint32_t> mRoads;
};