#include "Heap.h"
#include <iostream>

void MinHeap::bubbleUp(int index) {
	if (index <= 0) {
		return;
	}

	int parentIndex = getParentIndex(index);

	if (this->items[parentIndex] > this->items[index]) {
		//Swap items
		int temp = this->items[index];
		this->items[index] = this->items[parentIndex];
		this->items[parentIndex] = temp;
		bubbleUp(parentIndex);
	}
}

int MinHeap::getParentIndex(int index) {
	if (index == 0) {
		return -1; 
	}

	return (int)(index / 2);
}

int MinHeap::GetTopItem() {
	if (this->size <= 0)
	{
		std::cout << "ERROR: Heap is empty";
		return -1;
	}

	return items[0];
}

void MinHeap::InsertItem(int item) {
	if (this->size > MAX_SIZE) {
		std::cout << "Error: Heap is full"; 
		return;
	}

	items[this->size] = item;
	bubbleUp(this->size);
	this->size = this->size + 1;
}