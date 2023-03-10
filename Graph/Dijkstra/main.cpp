#include <cstdint>
#include <iostream>
#include <list>
#include <unordered_map>

#include "Node.h"
#include "Dijkstra.h"

std::unordered_map<const char*, Node*> CreateNodes();

int main()
{
	std::unordered_map<const char*, Node*> nodes = CreateNodes();
	std::unordered_map<const char*, const char*> prevs;
	std::unordered_map<const char*, uint32_t> minDists = Dijkstra::Run(nodes, "Home", prevs);

	uint32_t schoolDist = minDists.at("School");
	std::cout << schoolDist << std::endl;

	uint32_t bankDist = minDists.at("Bank");
	std::cout << bankDist << std::endl;

	uint32_t libDist = minDists.at("Library");
	std::cout << libDist << std::endl;

	std::list<const char*> path;

	const char* name = "School";
	while (name != nullptr)
	{
		path.push_front(name);
		name = prevs.at(name);
	}

	for (const char* name : path)
	{
		std::cout << name << " ";
	}

	return 0;
}

std::unordered_map<const char*, Node*> CreateNodes()
{
	Node* home = new Node("Home");
	Node* policeStation = new Node("PoliceStation");
	Node* school = new Node("School");
	Node* park = new Node("Park");
	Node* bank = new Node("Bank");
	Node* library = new Node("Library");

	home->AddRoad(policeStation, 2);
	policeStation->AddRoad(home, 2);

	home->AddRoad(park, 3);
	park->AddRoad(home, 3);

	policeStation->AddRoad(bank, 1);
	bank->AddRoad(policeStation, 1);

	policeStation->AddRoad(school, 6);
	school->AddRoad(policeStation, 6);

	bank->AddRoad(library, 2);
	library->AddRoad(bank, 2);

	bank->AddRoad(park, 2);
	park->AddRoad(bank, 2);

	school->AddRoad(library, 1);
	library->AddRoad(school, 1);

	std::unordered_map<const char*, Node*> nodes;

	nodes.insert({home->GetName(), home});
	nodes.insert({policeStation->GetName(), policeStation});
	nodes.insert({school->GetName(), school});
	nodes.insert({park->GetName(), park});
	nodes.insert({bank->GetName(), bank});
	nodes.insert({library->GetName(), library});

	return nodes;
}