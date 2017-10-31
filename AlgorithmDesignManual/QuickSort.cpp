#include "gtest/gtest.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

long long quicksort(vector<int> array, int low, int high) {

	return 0;
}

TEST(QuickSortTest, Basic) {
	vector<int> arr({ 1 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	EXPECT_EQ(result, 0);
	EXPECT_EQ(arr[0], 1);
}

TEST(QuickSortTest, TwoSorted) {
	vector<int> arr({ 1,2 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	EXPECT_EQ(result, 0);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
}

TEST(QuickSortTest, TwoUnsorted) {
	vector<int> arr({ 2,1 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	EXPECT_EQ(result, 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
}

TEST(QuickSortTest, ThreeBackward) {
	vector<int> arr({ 3,2,1 });
	auto result = quicksort(arr, 0, arr.size() - 1);
	EXPECT_EQ(result, 3);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
}
