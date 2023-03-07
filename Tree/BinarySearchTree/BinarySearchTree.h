#pragma once

#include <cstdint>

struct Node
{
	Node(int32_t data)
		: Data(data),
		RightChild(nullptr),
		LeftChild(nullptr)
	{
	}
	
	int32_t Data;
	Node* RightChild;
	Node* LeftChild;
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	
	Node* GetNodeOrNull(int32_t data) const;
	bool InsertNode(int32_t data);
	void RemoveNode(int32_t data);
	void ShowAllNodesOnConsole() const;
	
private:
	Node* getMinimumNodeRecursive(Node* current) const;
	Node* getNodeOrNullRecursive(Node* current, int32_t data) const;
	Node* insertNodeRecursive(Node* current, int32_t data);
	void iterateInorder(Node* current) const;
	Node* removeNodeRecursive(Node* current, int32_t data);
	
	Node* mRoot;
};
