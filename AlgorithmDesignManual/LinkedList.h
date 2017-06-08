#pragma once
#include <string>

class LinkedList {
public:
	int item;
	LinkedList *next = nullptr;
	LinkedList *prev = nullptr;
	LinkedList(int item);
	void Insert(LinkedList* item);
	LinkedList* ReverseRecursion();
	LinkedList* ReverseNoRecursion();
	void Delete(int item);
	LinkedList* FindNodeInCycle();
	std::string ToString();
};
