#pragma once

class MinHeap {
public:
	void InsertItem(int item);
	int PopTopItem();
	int Size = 0;
private:
	void bubbleUp(int index);
	void bubbleDown(int index);
	int getParentIndex(int index);
	int getFirstChildIndex(int index);
	static const int MAX_SIZE = 10000;
	int items[MAX_SIZE];
};

class MaxHeap {
public:
	void InsertItem(int item);
	int PopTopItem();
	int Size = 0;
private:
	void bubbleUp(int index);
	void bubbleDown(int index);
	int getParentIndex(int index);
	int getFirstChildIndex(int index);
	static const int MAX_SIZE = 10000;
	int items[MAX_SIZE];
};

