#include "gtest/gtest.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

void swap(vector<int> &array, int pos1, int pos2) {
	int temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
}

int partition(vector<int> &array, int low, int high) {
	int pivot = low;
	int pivotValue = array[pivot];

	//Swap pivot with first element
	//Temporarily pointless.
	swap(array, low, pivot);

	int i = low + 1;
	for (int j = low + 1; j <= high; j++) {
		if (array[j] < pivotValue) {
			//Swap
			swap(array, j, i);
			i = i + 1;
		}
	}

	//Put the partition element back in the correct place
	swap(array, low, i);

	return pivot;
}

long long quicksort(vector<int> &array, int low, int high) {
	if(low >= high)
		return 0;

	int pivot = partition(array, low, high);
	quicksort(array, low, pivot);
	quicksort(array, pivot + 1, high);

	return 0;
}

TEST(QuickSortTest, Basic) {
	vector<int> arr({ 1 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	//EXPECT_EQ(result, 0);
	EXPECT_EQ(arr[0], 1);
}

TEST(QuickSortTest, TwoSorted) {
	vector<int> arr({ 1,2 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	//EXPECT_EQ(result, 0);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
}

TEST(QuickSortTest, TwoUnsorted) {
	vector<int> arr({ 2,1 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	//EXPECT_EQ(result, 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
}

TEST(QuickSortTest, ThreeBackward) {
	vector<int> arr({ 3,2,1 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	//EXPECT_EQ(result, 3);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
}
