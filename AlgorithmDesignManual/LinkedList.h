#pragma once
#include <string>

class LinkedList {
public:
	int item;
	LinkedList *next = nullptr;
	LinkedList *prev = nullptr;
	LinkedList(int item);
	void Insert(LinkedList* item);
	void Delete(int item);
	LinkedList ToLinkedList();
	std::string ToString();
};
