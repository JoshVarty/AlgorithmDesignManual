#pragma once
#include <string>

class LinkedList {
public:
	int item;
	LinkedList *next = nullptr;
	LinkedList *prev = nullptr;
	LinkedList(int item);
	void Insert(int item);
	void Delete(int item);

	std::string ToString();
};