#pragma once

class MinHeap {
public:
	void InsertItem(int item);
	int GetTopItem();
private:
	void BubbleUp(int index);
	int size = 0;
	const int MAX_SIZE = 10000;
	int items[MAX_SIZE];
};

