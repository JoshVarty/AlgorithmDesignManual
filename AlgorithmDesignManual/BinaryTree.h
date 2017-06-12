#pragma once
#include <string>
#include "LinkedList.h"

class BinaryTree {
public:
	int item;
	BinaryTree *parent = nullptr;
	BinaryTree *left = nullptr;
	BinaryTree *right = nullptr;

	BinaryTree(int item);
	BinaryTree * SearchTree(int searchValue);
	BinaryTree * FindMinimum();
	void Insert(BinaryTree * node);
	bool IsIdentical(BinaryTree * otherRoot);
	LinkedList* ToLinkedList();
	bool IsValidBinaryTree(int lowerBound, int upperBound);
	bool IsValidBinaryTree();
	std::string ToString();
};
