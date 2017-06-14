#pragma once

class MinHeap {
public:
	void InsertItem(int item);
	int GetTopItem();
private:
	void BubbleUp(int item);
	int size = 0;
	int items[10000];
};

