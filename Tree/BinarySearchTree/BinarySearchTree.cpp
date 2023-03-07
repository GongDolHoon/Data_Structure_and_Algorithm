#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
	: mRoot(nullptr)
{	
}

BinarySearchTree::~BinarySearchTree()
{	
}

Node* BinarySearchTree::GetNodeOrNull(int32_t data) const
{
	if(mRoot == nullptr)
	{
		std::cout << "No node is in the BST." << std::endl;				
	}
	
	return getNodeOrNullRecursive(mRoot, data);
}

bool BinarySearchTree::InsertNode(int32_t data)
{
	if(mRoot == nullptr)
	{
		mRoot = new Node(data);
		return true;
	}
	
	if(insertNodeRecursive(mRoot, data) == nullptr)
	{
		return false;
	}
	
	return true;
}

void BinarySearchTree::RemoveNode(int32_t data)
{
	if(mRoot == nullptr)
	{
		std::cout << "No node is in the BST." << std::endl;	
	}
	
	removeNodeRecursive(mRoot, data);
}

void BinarySearchTree::ShowAllNodesOnConsole() const
{
	if(mRoot == nullptr)
	{
		std::cout << "No node is in the BST." << std::endl;
	}
	
	iterateInorder(mRoot);
	std::cout << std::endl;
}

// If you use getMinimumNodeRecursive() in removeNodeRecursive(),
// you have to input current->Right for the parameter.
Node* BinarySearchTree::getMinimumNodeRecursive(Node* current) const
{
	if(current == nullptr)
	{
		return nullptr;
	}
	
	if(current->LeftChild == nullptr)
	{
		return current;
	}
	else
	{
		return getMinimumNodeRecursive(current);
	}
}

Node* BinarySearchTree::getNodeOrNullRecursive(Node* current, int32_t data) const
{
	if(current == nullptr)
	{
		return nullptr;
	}
	
	if(current->Data == data)
	{
		return current;
	}
	
	if(current->Data > data)
	{
		return getNodeOrNullRecursive(current->LeftChild, data);
	}
	else
	{
		return getNodeOrNullRecursive(current->RightChild, data);
	}
}

Node* BinarySearchTree::insertNodeRecursive(Node* current, int32_t data)
{
	if(current == nullptr)
	{
		current = new Node(data);	
	}
	
	if (current->Data > data)
	{
		current->LeftChild = insertNodeRecursive(current->LeftChild, data);
	}
	else if (current->Data < data)
	{
		current->RightChild = insertNodeRecursive(current->RightChild, data);
	}

	return current;
}

void BinarySearchTree::iterateInorder(Node* current) const
{
	if(current == nullptr)
	{
		return;
	}
	
	iterateInorder(current->LeftChild);
	std::cout << current->Data << " ";
	iterateInorder(current->RightChild);
}

Node* BinarySearchTree::removeNodeRecursive(Node* current, int32_t data)
{
	if(current == nullptr)
	{
		return nullptr;
	}
	
	if(current->Data > data)
	{
		current->LeftChild = removeNodeRecursive(current->LeftChild, data);
	}
	else if(current->Data < data)
	{
		current->RightChild = removeNodeRecursive(current->RightChild, data);
	}
	else
	{
		Node* tmp;
		
		if(current->RightChild == nullptr && current->LeftChild == nullptr)
		{
			delete current;
			current = nullptr;
		}
		else if (current->RightChild == nullptr)
		{
			tmp = current;
			current = current->LeftChild;
			delete tmp;
		}
		else if (current->LeftChild == nullptr)
		{
			tmp = current;
			current = current->RightChild;
			delete tmp;
		}
		else
		{
			tmp = getMinimumNodeRecursive(current->RightChild);
			current->Data = tmp->Data;
			current->RightChild = removeNodeRecursive(current->RightChild, current->Data);
		}
	}
	
	return current;
}
