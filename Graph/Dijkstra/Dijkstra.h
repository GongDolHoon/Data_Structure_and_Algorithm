#pragma once

#include <cstdint>
#include <queue>
#include <unordered_map>

#include "Candidate.h"
#include "Node.h"

class Dijkstra final
{
public:
	Dijkstra() = default;
	~Dijkstra() = default;

	static std::unordered_map<const char*, uint32_t> Run(std::unordered_map<const char*, Node*>& nodes, const char* from, std::unordered_map<const char*, const char*>& prevs)
	{
		std::unordered_map<const char*, uint32_t> minDists; 

		const uint32_t INF = UINT32_MAX;
		for (auto node : nodes)
		{
			const char* name = node.first;

			minDists.insert({name, INF});
		}

		minDists.erase(from);
		minDists.insert({from, 0});

		prevs.insert({from, nullptr});

		std::priority_queue<Candidate*> open;

		Node* s = nodes.at(from);
		Candidate* candidate = new Candidate(s, 0);

		open.push(candidate);

		while (!open.empty())
		{
			candidate = open.top();
			open.pop();

			Node* n = candidate->GetNode();
			const char* nodeName = n->GetName();

			uint32_t minDist = minDists.at(nodeName);
			uint32_t dist = candidate->GetDistance();

			if (minDist < dist)
			{
				continue;
			}

			std::unordered_map<Node*, uint32_t> roads = n->GetRoads();

			for (auto e : roads)
			{
				Node* next = e.first;

				uint32_t weight = e.second;
				uint32_t newDist = minDist + weight;

				const char* nextName = next->GetName();
				uint32_t nextMinDist = minDists.at(nextName);

				if (newDist >= nextMinDist)
				{
					continue;
				}

				minDists.erase(nextName);
				minDists.insert({nextName, newDist});

				prevs.erase(nextName);
				prevs.insert({nextName, nodeName});

				Candidate* newCandidate = new Candidate(next, newDist);

				open.push(newCandidate);
			}
		}

		return minDists;
	}
};

