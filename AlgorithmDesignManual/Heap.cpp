#include "Heap.h"
#include <iostream>

#pragma region MinHeap

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

void MinHeap::bubbleDown(int index) {
	int childIndex = getFirstChildIndex(index);
	int minIndex = index;

	for (int i = 0; i <= 1; i++) {
		if (childIndex + i <= this->Size) {
			if (this->items[minIndex] > this->items[childIndex + i]) {
				minIndex = childIndex + i;
			}
		}
	}

	if (minIndex != index) {
		int temp = this->items[index];
		this->items[index] = this->items[minIndex];
		this->items[minIndex] = temp;
		bubbleDown(minIndex);
	}
}

int MinHeap::getParentIndex(int index) {
	if (index == 0) {
		return -1; 
	}

	return (int)(index / 2);
}

int MinHeap::getFirstChildIndex(int index) {
	return index * 2;
}

int MinHeap::GetTopItem() {
	if (this->Size <= 0)
	{
		std::cout << "ERROR: Heap is empty";
		return -1;
	}

	int min = items[0];
	return min;
}

int MinHeap::PopTopItem() {
	if (this->Size <= 0)
	{
		std::cout << "ERROR: Heap is empty";
		return -1;
	}

	int min = items[0];
	this->items[0] = this->items[this->Size - 1];
	this->Size = this->Size - 1;
	this->bubbleDown(0);

	return min;
}

void MinHeap::InsertItem(int item) {
	if (this->Size > MAX_SIZE) {
		std::cout << "Error: Heap is full"; 
		return;
	}

	items[this->Size] = item;
	bubbleUp(this->Size);
	this->Size = this->Size + 1;
}

#pragma endregion

#pragma region MaxHeap

void MaxHeap::bubbleUp(int index) {
	if (index <= 0) {
		return;
	}

	int parentIndex = getParentIndex(index);

	if (this->items[parentIndex] < this->items[index]) {
		//Swap items
		int temp = this->items[index];
		this->items[index] = this->items[parentIndex];
		this->items[parentIndex] = temp;
		bubbleUp(parentIndex);
	}
}

void MaxHeap::bubbleDown(int index) {
	int childIndex = getFirstChildIndex(index);
	int maxIndex = index;

	for (int i = 0; i <= 1; i++) {
		if (childIndex + i <= this->Size) {
			if (this->items[maxIndex] < this->items[childIndex + i]) {
				maxIndex = childIndex + i;
			}
		}
	}

	if (maxIndex != index) {
		int temp = this->items[index];
		this->items[index] = this->items[maxIndex];
		this->items[maxIndex] = temp;
		bubbleDown(maxIndex);
	}
}

int MaxHeap::getParentIndex(int index) {
	if (index == 0) {
		return -1; 
	}

	return (int)(index / 2);
}

int MaxHeap::getFirstChildIndex(int index) {
	return index * 2;
}

int MaxHeap::GetTopItem() {
	if (this->Size <= 0)
	{
		std::cout << "ERROR: Heap is empty";
		return -1;
	}

	int max = items[0];
	return max;
}

int MaxHeap::PopTopItem() {
	if (this->Size <= 0)
	{
		std::cout << "ERROR: Heap is empty";
		return -1;
	}

	int max = items[0];
	this->items[0] = this->items[this->Size - 1];
	this->Size = this->Size - 1;
	this->bubbleDown(0);

	return max;
}

void MaxHeap::InsertItem(int item) {
	if (this->Size > MAX_SIZE) {
		std::cout << "Error: Heap is full"; 
		return;
	}

	items[this->Size] = item;
	bubbleUp(this->Size);
	this->Size = this->Size + 1;
}

#pragma endregion
