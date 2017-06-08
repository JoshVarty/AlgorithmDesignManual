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

	LinkedList* lastItem = this;
	auto* currentItem = this;

	while (currentItem != nullptr) {
		//iterate
		lastItem = currentItem;
		currentItem = lastItem->next;
		//adjust pointers
		lastItem->next = lastItem->prev;
		lastItem->prev = currentItem;
	}
	
	return lastItem;
}

LinkedList * LinkedList::FindNodeInCycle() {
	LinkedList * fast = this;
	LinkedList * slow = this;

	while (fast->next != nullptr && fast->next->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
		{
			return fast;
		}
	}

	return nullptr;
}
