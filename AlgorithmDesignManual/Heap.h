#pragma once

class MinHeap {
public:
	void InsertItem(int item);
	int PopTopItem();
private:
	void bubbleUp(int index);
	void bubbleDown(int index);
	int size = 0;
	int getParentIndex(int index);
	int getFirstChildIndex(int index);
	static const int MAX_SIZE = 10000;
	int items[MAX_SIZE];
};

class MaxHeap {
public:
	void InsertItem(int item);
	int GetTopItem();
private:
	void bubbleUp(int index);
	int size = 0;
	int getParentIndex(int index);
	static const int MAX_SIZE = 10000;
	int items[MAX_SIZE];
};

