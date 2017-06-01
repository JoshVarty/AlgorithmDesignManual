#pragma once
#include <string>

class BinaryTree {
public:
	int item;
	BinaryTree *parent = nullptr;
	BinaryTree *left = nullptr;
	BinaryTree *right = nullptr;

	BinaryTree * SearchTree(int searchValue);
	BinaryTree * FindMinimum();
	BinaryTree(int item);

	std::string ToString();
	void Insert(BinaryTree * node);

	//Not sure about this one
	void Delete(int value);
};
