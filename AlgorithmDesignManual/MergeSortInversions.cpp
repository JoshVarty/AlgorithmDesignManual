#include "gtest/gtest.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

long long merge(vector<int> &array, long long low, long long middle, long long high) {
	long long inversions = 0;
	auto q1 = new queue<int>();
	auto q2 = new queue<int>();

	for (int i = low; i <= middle; i++) {
		q1->push(array[i]);
	}
	for (int i = middle + 1; i <= high; i++) {
		q2->push(array[i]);
	}

	int i = low;
	while (!q1->empty() && !q2->empty()) {
		if (q1->front() <= q2->front()) {
			array[i] = q1->front();
			q1->pop();
		}
		else {
			array[i] = q2->front();
			q2->pop();
		}
		i = i + 1;
	}

	while (!q1->empty()) {
		array[i] = q1->front();
		q1->pop();
		i = i + 1;
	}
	while (!q2->empty()) {
		array[i] = q2->front();
		q2->pop();
		i = i + 1;
	}

	return 0;
}


long long mergesort(vector<int> &array, long long low, long long high) {
	if (low >= high) {
		return 0;
	}

	long long middle = (low + high) / 2;
	auto s1 = mergesort(array, low, middle);
	auto s2 = mergesort(array, middle + 1, high);
	auto s3 = merge(array, low, middle, high);
	return s1 + s2 + s3;
}

TEST(MergeSortTest, Basic) {
	vector<int> arr({ 1 });
	auto result = mergesort(arr, 0, arr.size() - 1); 
	EXPECT_EQ(result, 0);
	EXPECT_EQ(arr[0], 1);
	cout << result << endl;
}

TEST(MergeSortTest, TwoSorted) {
	vector<int> arr({ 1,2 });
	auto result = mergesort(arr, 0, arr.size() - 1); 
	//EXPECT_EQ(result, 0);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	cout << result << endl;
}

TEST(MergeSortTest, TwoUnsorted) {
	vector<int> arr({ 2,1 });
	auto result = mergesort(arr, 0, arr.size() - 1); 
	//EXPECT_EQ(result, 1);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	cout << result << endl;
}
TEST(MergeSortTest, ThreeBackward) {
	vector<int> arr({ 3,2,1 });
	auto result = mergesort(arr, 0, arr.size() - 1); 
	//EXPECT_EQ(result, 2);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	cout << result << endl;
}
