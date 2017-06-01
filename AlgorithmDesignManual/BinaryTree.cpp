//A little binary tree for a little repo
#include "BinaryTree.h"
#include <string>

BinaryTree::BinaryTree(int item) {
	this->item = item;
}

void BinaryTree::Insert(BinaryTree * newNode) {
	
	if (this->item < newNode->item) {
		//put it right
		if (this->right == nullptr) {
			this->right = newNode;
			newNode->parent = this;
		}
		else {
			this->right->Insert(newNode);
		}
	}
	else {
		if (this->left == nullptr) {
			this->left = newNode;
			newNode->parent = this;
		}
		else {
			this->left->Insert(newNode);
		}
	}
}

std::string BinaryTree::ToString() {
	std::string result = "";

	if (this->left != nullptr) {
		result = result + this->left->ToString();
	}

	result = result + "," + std::to_string(this->item);

	if (this->right != nullptr) {
		result = result + this->right->ToString();
	}

	return result;
}