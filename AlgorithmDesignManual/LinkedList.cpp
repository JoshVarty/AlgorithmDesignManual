#include "LinkedList.h"

LinkedList::LinkedList(int item) {
	this->item = item;
}

void LinkedList::Insert(int item) {

	auto* iterator = this;
	while (iterator->next != nullptr) {
		iterator = iterator->next;
	}

	auto* newNode = new LinkedList(item);
	newNode->prev = iterator;
	iterator->next = newNode;
}
