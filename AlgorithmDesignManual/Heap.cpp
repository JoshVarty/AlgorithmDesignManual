#include "Heap.h"
#include <iostream>

void MinHeap::BubbleUp(int index) {

}

int MinHeap::GetTopItem() {
	return items[this->size - 1];
}

void MinHeap::InsertItem(int item) {
	if (this->size > MAX_SIZE) {
		std::cout << "Error: Heap is full"; 
		return;
	}

	items[this->size] = item;
	BubbleUp(this->size);
	this->size = this->size + 1;
}