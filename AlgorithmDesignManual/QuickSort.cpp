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


int partition_lastelement(vector<int> &array, int low, int high) {
	int pivot = high;
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

long long quicksort_lastelement(vector<int> &array, int low, int high) {
	if (low >= high)
		return 0;

	int pivot = partition_lastelement(array, low, high);

	int a = max((pivot - 1) - low, 0);
	int b = quicksort_lastelement(array, low, pivot - 1);
	int c = max(high - (pivot + 1), 0);
	int d = quicksort_lastelement(array, pivot + 1, high);

	return a + b + c + d;
}


int partition_firstelement(vector<int> &array, int low, int high) {
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

long long quicksort_firstelement(vector<int> &array, int low, int high) {
	if(low >= high)
		return 0;

	int pivot = partition_firstelement(array, low, high);

	int a = max((pivot - 1) - low, 0);	
	int b = quicksort_firstelement(array, low, pivot - 1);
	int c = max(high - (pivot + 1), 0);
	int d = quicksort_firstelement(array, pivot + 1, high);

	return a + b + c + d;
}

#pragma region QuickSort_FirstElement

TEST(QuickSortTest_First, Basic) {
	vector<int> arr({ 1 });
	auto result = quicksort_firstelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
}

TEST(QuickSortTest_First, TwoSorted) {
	vector<int> arr({ 1,2 });
	auto result = quicksort_firstelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
}

TEST(QuickSortTest_First, TwoUnsorted) {
	vector<int> arr({ 2,1 });
	auto result = quicksort_firstelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
}

TEST(QuickSortTest_First, ThreeBackward) {
	vector<int> arr({ 3,2,1 });
	auto result = quicksort_firstelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
}

TEST(QuickSortTest_First, Three) {
	vector<int> arr({ 2,3,1 });
	auto result = quicksort_firstelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
}

TEST(QuickSortTest_First, FiveBackward) {
	vector<int> arr({ 5,4,3,2,1 });
	auto result = quicksort_firstelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}

TEST(QuickSortTest_First, Four) {
	vector<int> arr({ 1,4,2,3 });
	auto result = quicksort_firstelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
}

TEST(QuickSortTest_First, dgrcode_01) {
	vector<int> arr({ 3, 2, 1, 4, 5 });

	auto result = quicksort_firstelement(arr, 0, arr.size() - 1);
	result = result + arr.size() - 1;
	EXPECT_EQ(result, 6);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}

TEST(QuickSortTest_First, dgrcode_02) {
	vector<int> arr({ 4, 3, 2, 5, 1 });

	auto result = quicksort_firstelement(arr, 0, arr.size() - 1);
	result = result + arr.size() - 1;
	EXPECT_EQ(result, 7);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}

TEST(QuickSortTest_First, dgrcode_15_20) {
	vector<int> arr({ 2,1,12,13,16,10,9,5,18,8,17,20,19,3,4,11,14,6,7,15 });

	auto result = quicksort_firstelement(arr, 0, arr.size() - 1);
	result = result + arr.size() - 1;
	EXPECT_EQ(result, 69);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}

#pragma endregion



#pragma region QuickSort_LastElement

TEST(QuickSortTest_Last, Basic) {
	vector<int> arr({ 1 });
	auto result = quicksort_lastelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
}

TEST(QuickSortTest_Last, TwoSorted) {
	vector<int> arr({ 1,2 });
	auto result = quicksort_lastelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
}

TEST(QuickSortTest_Last, TwoUnsorted) {
	vector<int> arr({ 2,1 });
	auto result = quicksort_lastelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
}

TEST(QuickSortTest_Last, ThreeBackward) {
	vector<int> arr({ 3,2,1 });
	auto result = quicksort_lastelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
}

TEST(QuickSortTest_Last, Three) {
	vector<int> arr({ 2,3,1 });
	auto result = quicksort_lastelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
}

TEST(QuickSortTest_Last, FiveBackward) {
	vector<int> arr({ 5,4,3,2,1 });
	auto result = quicksort_lastelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}

TEST(QuickSortTest_Last, Four) {
	vector<int> arr({ 1,4,2,3 });
	auto result = quicksort_lastelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
}

TEST(QuickSortTest_Last, dgrcode_01) {
	vector<int> arr({ 3, 2, 1, 4, 5 });

	auto result = quicksort_lastelement(arr, 0, arr.size() - 1);
	result = result + arr.size() - 1;
	EXPECT_EQ(result, 10);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}

TEST(QuickSortTest_Last, dgrcode_02) {
	vector<int> arr({ 4, 3, 2, 5, 1 });

	auto result = quicksort_lastelement(arr, 0, arr.size() - 1);
	result = result + arr.size() - 1;
	EXPECT_EQ(result, 8);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}

TEST(QuickSortTest_Last, dgrcode_15_20) {
	vector<int> arr({ 2,1,12,13,16,10,9,5,18,8,17,20,19,3,4,11,14,6,7,15 });

	auto result = quicksort_lastelement(arr, 0, arr.size() - 1);
	result = result + arr.size() - 1;
	EXPECT_EQ(result, 65);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}

#pragma endregion
