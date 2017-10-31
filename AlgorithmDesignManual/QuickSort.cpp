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
	swap(array, low, i - 1);

	return i - 1;
}

long long quicksort(vector<int> &array, int low, int high) {
	if(low >= high)
		return 0;

	int pivot = partition(array, low, high);

	int a = max((pivot - 1) - low, 0);	
	int b = quicksort(array, low, pivot - 1);
	int c = max(high - (pivot + 1), 0);
	int d = quicksort(array, pivot + 1, high);

	return a + b + c + d;
}

TEST(QuickSortTest, Basic) {
	vector<int> arr({ 1 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
}

TEST(QuickSortTest, TwoSorted) {
	vector<int> arr({ 1,2 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
}

TEST(QuickSortTest, TwoUnsorted) {
	vector<int> arr({ 2,1 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
}

TEST(QuickSortTest, ThreeBackward) {
	vector<int> arr({ 3,2,1 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
}

TEST(QuickSortTest, Three) {
	vector<int> arr({ 2,3,1 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
}


TEST(QuickSortTest, FiveBackward) {
	vector<int> arr({ 5,4,3,2,1 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}


TEST(QuickSortTest, Four) {
	vector<int> arr({ 1,4,2,3 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
}


TEST(QuickSortTest, dgrcode_01) {
	vector<int> arr({ 3, 2, 1, 4, 5 });

	auto result = quicksort(arr, 0, arr.size() - 1);
	result = result + arr.size() - 1;
	EXPECT_EQ(result, 6);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}


TEST(QuickSortTest, dgrcode_02) {
	vector<int> arr({ 4, 3, 2, 5, 1 });

	auto result = quicksort(arr, 0, arr.size() - 1);
	result = result + arr.size() - 1;
	EXPECT_EQ(result, 7);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}

TEST(QuickSortTest, dgrcode_15_20) {
	vector<int> arr({ 2,1,12,13,16,10,9,5,18,8,17,20,19,3,4,11,14,6,7,15 });

	auto result = quicksort(arr, 0, arr.size() - 1);
	result = result + arr.size() - 1;
	EXPECT_EQ(result, 69);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}

