#include "LinkedList.h"

LinkedList::LinkedList(int item) {
	this->item = item;
}

void LinkedList::Insert(LinkedList* item) {

	auto* iterator = this;
	while (iterator->next != nullptr) {
		iterator = iterator->next;
	}
	item->prev = iterator;
	iterator->next = item;
}

std::string LinkedList::ToString() {
	
	auto* iterator = this;
	std::string result = std::to_string(iterator->item);

	while (iterator->next != nullptr) {
		iterator = iterator->next;
		result = result + "," + std::to_string(iterator->item);
	}

	return result;
}

LinkedList * LinkedList::ReverseRecursion() {
	
	auto* tempNext = this->next;
	this->next = this->prev;
	this->prev = tempNext;
	
	if (tempNext != nullptr) {
		return tempNext->ReverseRecursion();
	}

	return this;
}

LinkedList * LinkedList::ReverseNoRecursion() {

	LinkedList* tempNext = this;

	while (this->next != nullptr) {
		tempNext = this->next;
		this->next = this->prev;
		this->prev = tempNext;
	}
	
	return tempNext;
}
