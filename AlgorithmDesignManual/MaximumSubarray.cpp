#include "gtest/gtest.h"

using namespace std;

int getSumOfMaxSubarray(int sequence[], int length) {

	int max = sequence[0];
	int maxEndingHere = sequence[0];
	
	for (int i = 1; i < length; i++) {
		int item = sequence[i];
		maxEndingHere = std::max(item, maxEndingHere + item);
		max = std::max(max, maxEndingHere);
	}

	return max;
}

TEST(MaximumSubarrayTests, OneItem)
{
	int sequence[1] = { 1 };
	int length = sizeof(sequence) / sizeof(sequence[0]);

	int sumOfMaxSubarray = getSumOfMaxSubarray(sequence, length);
	EXPECT_EQ(sumOfMaxSubarray, 1);
}

TEST(MaximumSubarrayTests, ThreeItemsAllPositive)
{
	int sequence[3] = { 1, 2, 3 };
	int length = sizeof(sequence) / sizeof(sequence[0]);

	int sumOfMaxSubarray = getSumOfMaxSubarray(sequence, length);
	EXPECT_EQ(sumOfMaxSubarray, 6);
}

TEST(MaximumSubarrayTests, FiveItemsWithNegative)
{
	int sequence[5] = { 1, 2, -1, 4, 5 };
	int length = sizeof(sequence) / sizeof(sequence[0]);

	int sumOfMaxSubarray = getSumOfMaxSubarray(sequence, length);
	EXPECT_EQ(sumOfMaxSubarray, 11);
}

TEST(MaximumSubarrayTests, FiveItemsWithNegative2)
{
	int sequence[5] = { 4, 5, -1, 1, 2 };
	int length = sizeof(sequence) / sizeof(sequence[0]);

	int sumOfMaxSubarray = getSumOfMaxSubarray(sequence, length);
	EXPECT_EQ(sumOfMaxSubarray, 11);
}

TEST(MaximumSubarrayTests, Example)
{
	int sequence[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int length = sizeof(sequence) / sizeof(sequence[0]);

	int sumOfMaxSubarray = getSumOfMaxSubarray(sequence, length);
	EXPECT_EQ(sumOfMaxSubarray, 6);
}
