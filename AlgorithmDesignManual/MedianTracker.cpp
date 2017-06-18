#include "MedianTracker.h"
#include <algorithm>

MedianTracker::MedianTracker() {
		minHeap->InsertItem(INT_MAX);
		minHeap->InsertItem(INT_MAX);
		minHeap->InsertItem(INT_MAX);
		
		maxHeap->InsertItem(INT_MIN);
		maxHeap->InsertItem(INT_MIN);
		maxHeap->InsertItem(INT_MIN);
}

void Sort(double &a, double &b, double &c) {
	if (a > b) {
		std::swap(a, b);
	}
	if (a > c) {
		std::swap(a, c);
	}
	if (b > c) {
		std::swap(b, c);
	}
}

double MedianTracker::AddItem(int item) {

	double bigItem = (double)minHeap->PopTopItem();
	double smallItem = (double)maxHeap->PopTopItem();
	double middleItem = (double)item;

	Sort(smallItem, middleItem, bigItem);

	maxHeap->InsertItem(smallItem);
	minHeap->InsertItem(bigItem);

	if (maxHeap->Size == minHeap->Size) {
		minHeap->InsertItem(middleItem);
		median = middleItem;
	}
	else if (maxHeap->Size > minHeap->Size) {
		minHeap->InsertItem(middleItem);
		int item1 = minHeap->GetTopItem();
		int item2 = maxHeap->GetTopItem();
		median = (item1 + item2) / 2.0;
	}
	else {
		maxHeap->InsertItem(middleItem);
		int item1 = minHeap->GetTopItem();
		int item2 = maxHeap->GetTopItem();
		median = (item1 + item2) / 2.0;
	}

	return median;
}