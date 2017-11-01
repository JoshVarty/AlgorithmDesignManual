#include "gtest/gtest.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void swap(vector<int> &array, int pos1, int pos2) {
	int temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
}

int getMedianIndex(vector<int> &array, int firstIndex, int lastIndex) {
	int middleIndex = ((lastIndex - firstIndex) / 2) + firstIndex;

	int first = array[firstIndex];
	int middle = array[middleIndex];
	int last = array[lastIndex];
	
	int medianValue = max(min(first, middle), min(max(first, middle), last));

	if (medianValue == first) {
		return firstIndex;
	}
	else if (medianValue == middle) {
		return middleIndex;
	}
	else {
		return lastIndex;
	}
}

int partition_medianelement(vector<int> &array, int low, int high) {

	int pivot = getMedianIndex(array, low, high);
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

long long quicksort_medianelement(vector<int> &array, int low, int high) {
	if (low >= high)
		return 0;

	int pivot = partition_medianelement(array, low, high);

	int a = max((pivot - 1) - low, 0);
	int b = quicksort_medianelement(array, low, pivot - 1);
	int c = max(high - (pivot + 1), 0);
	int d = quicksort_medianelement(array, pivot + 1, high);

	return a + b + c + d;
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


#pragma region QuickSort_MedianElement

TEST(QuickSortTest_Median, Basic) {
	vector<int> arr({ 1 });
	auto result = quicksort_medianelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
}

TEST(QuickSortTest_Median, TwoSorted) {
	vector<int> arr({ 1,2 });
	auto result = quicksort_medianelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
}

TEST(QuickSortTest_Median, TwoUnsorted) {
	vector<int> arr({ 2,1 });
	auto result = quicksort_medianelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
}

TEST(QuickSortTest_Median, ThreeBackward) {
	vector<int> arr({ 3,2,1 });
	auto result = quicksort_medianelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
}

TEST(QuickSortTest_Median, Three) {
	vector<int> arr({ 2,3,1 });
	auto result = quicksort_medianelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
}

TEST(QuickSortTest_Median, FiveBackward) {
	vector<int> arr({ 5,4,3,2,1 });
	auto result = quicksort_medianelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}

TEST(QuickSortTest_Median, Four) {
	vector<int> arr({ 1,4,2,3 });
	auto result = quicksort_medianelement(arr, 0, arr.size() - 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
}

TEST(QuickSortTest_Median, dgrcode_01) {
	vector<int> arr({ 3, 2, 1, 4, 5 });

	auto result = quicksort_medianelement(arr, 0, arr.size() - 1);
	result = result + arr.size() - 1;
	EXPECT_EQ(result, 6);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}

TEST(QuickSortTest_Median, dgrcode_02) {
	vector<int> arr({ 4, 3, 2, 5, 1 });

	auto result = quicksort_medianelement(arr, 0, arr.size() - 1);
	result = result + arr.size() - 1;
	EXPECT_EQ(result, 6);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}

TEST(QuickSortTest_Median, dgrcode_15_20) {
	vector<int> arr({ 2,1,12,13,16,10,9,5,18,8,17,20,19,3,4,11,14,6,7,15 });

	auto result = quicksort_medianelement(arr, 0, arr.size() - 1);
	result = result + arr.size() - 1;
	EXPECT_EQ(result, 56);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 5);
}


#pragma endregion


#pragma region MedianTests


TEST(MedianTests, Three) {
	vector<int> arr({ 1,2,3 });
	int medianIndex = getMedianIndex(arr, 0, arr.size() - 1);
	EXPECT_EQ(medianIndex, 1);
}


TEST(MedianTests, CourseraExample) {
	vector<int> arr({ 4,5,6,7 });
	int medianIndex = getMedianIndex(arr, 0, arr.size() - 1);
	EXPECT_EQ(medianIndex, 1);
}

TEST(MedianTests, CourseraExample2) {
	vector<int> arr({ 8, 2, 4, 5, 7, 1 });
	int medianIndex = getMedianIndex(arr, 3, arr.size() - 1);
	EXPECT_EQ(medianIndex, 3);
}


#pragma endregion



TEST(QuickSortTests, AllTests) {
	ifstream fileWithNumbers("");
	ifstream fileWithAnswers("");

	vector<int> array1;
	vector<int> array2;
	vector<int> array3;
	string currentLine = "";
	while (getline(fileWithNumbers, currentLine)) {
		int currentNum = stoi(currentLine);
		array1.push_back(currentNum);
		array2.push_back(currentNum);
		array3.push_back(currentNum);
	}

	vector<int> answers;
	while (getline(fileWithAnswers, currentLine)) {
		int currentAnswer = stoi(currentLine);
		answers.push_back(currentAnswer);
	}

	auto result1 = quicksort_firstelement(array1, 0, array1.size() - 1);
	auto result2 = quicksort_lastelement(array2, 0, array2.size() - 1);
	auto result3 = quicksort_medianelement(array3, 0, array3.size() - 1);

	EXPECT_EQ(result1, answers[0]);
	EXPECT_EQ(result2, answers[1]);
	EXPECT_EQ(result3, answers[2]);
}
