#pragma once
#include "Heap.h"
#include <climits>

class MedianTracker {
private:
	MinHeap *minHeap = new MinHeap();
	MaxHeap *maxHeap = new MaxHeap();
	double median = INT_MIN;
public:
	double AddItem(int item);
	MedianTracker();
};
