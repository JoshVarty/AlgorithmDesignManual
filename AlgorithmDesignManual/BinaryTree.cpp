//A little binary tree for a little repo
#include "BinaryTree.h"
#include <string>

BinaryTree::BinaryTree(int item) {
	this->item = item;
}

BinaryTree * BinaryTree::SearchTree(int searchValue) {
	if (searchValue == this->item) {
		return this;
	}

	if (searchValue > this->item && this->right != nullptr) {
		return this->right->SearchTree(searchValue);
	}
	else if (searchValue < this->item && this->left != nullptr) {
		return this->left->SearchTree(searchValue);
	}

	//It's not here, the left, or right
	return nullptr;
}

BinaryTree * BinaryTree::FindMinimum() {
	if (this->left == nullptr) {
		return this;
	}

	return this->left->FindMinimum();
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

bool BinaryTree::IsIdentical(BinaryTree * otherRoot) {

	//If we don't have the same value, return false
	if (this->item != otherRoot->item) {
		return false;
	}

	//If we don't have similar child shape, return false
	if ((this->left == nullptr && otherRoot->left != nullptr)
		|| (this->left != nullptr && otherRoot->left == nullptr)
		|| (this->right == nullptr && otherRoot->right != nullptr)
		|| (this->right != nullptr && otherRoot->right == nullptr)) {
		return false;
	}
	
	//If there are children, visit them
	bool leftEqual = true;
	if (this->left != nullptr && otherRoot->left != nullptr) {
		leftEqual = this->left->IsIdentical(otherRoot->left);
	}

	bool rightEqual = true;
	if (this->right != nullptr && otherRoot->right != nullptr) {
		rightEqual = this->right->IsIdentical(otherRoot->right);
	}
	
	return leftEqual & rightEqual;
}

LinkedList* BinaryTree::ToLinkedList() {

	LinkedList* node = new LinkedList(this->item);
	LinkedList* head = node;

	if (this->left != nullptr) {
		head = this->left->ToLinkedList();
		head->Insert(node);
	}

	if (this->right != nullptr) {
		head->Insert(this->right->ToLinkedList());
	}

	return head;
}

bool BinaryTree::IsValidBinaryTree() {
	return false;
}

std::string BinaryTree::ToString() {
	std::string result = std::to_string(this->item);

	if (this->left != nullptr) {
		std::string left = this->left->ToString();
		if (!left.empty()) {
			result = left + "," + result;
		}
	}

	if (this->right != nullptr) {
		std::string right = this->right->ToString();
		if (!right.empty()) {
			result = result + "," + right;
		}
	}

	return result;
}

