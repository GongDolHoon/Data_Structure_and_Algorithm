#include <iostream>
#include "BinarySearchTree.h"

int main() {
	
	BinarySearchTree* bst = new BinarySearchTree();
	
	bst->InsertNode(58);
	bst->InsertNode(10);
	bst->InsertNode(35);
	bst->InsertNode(32);
	bst->InsertNode(50);
	bst->ShowAllNodesOnConsole();
	
	bst->RemoveNode(50);
	bst->RemoveNode(35);
	bst->ShowAllNodesOnConsole();
	
	return 0;
}
