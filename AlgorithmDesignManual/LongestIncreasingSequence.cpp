#include "gtest/gtest.h"

using namespace std;


int getLengthOfLongestIncreasingSequence(int sequence[], int length) {
	return -1;
}


TEST(LongestIncreasingSequenceTests, OneItem)
{
	int sequence[1] = { 1 };
	int length = sizeof(sequence) / sizeof(sequence[0]);

	int lengthOfLongestIncreasingSequence = getLengthOfLongestIncreasingSequence(sequence, length);
	EXPECT_EQ(lengthOfLongestIncreasingSequence, 1);
}

TEST(LongestIncreasingSequenceTests, ThreeIncreasingItems)
{
	int sequence[3] = { 1, 2, 3 };
	int length = sizeof(sequence) / sizeof(sequence[0]);

	int lengthOfLongestIncreasingSequence = getLengthOfLongestIncreasingSequence(sequence, length);
	EXPECT_EQ(lengthOfLongestIncreasingSequence, 3);
}

TEST(LongestIncreasingSequenceTests, ThreeIncreasingItemsAfterLargeItem)
{
	int sequence[4] = { 5, 1, 2, 3 };
	int length = sizeof(sequence) / sizeof(sequence[0]);

	int lengthOfLongestIncreasingSequence = getLengthOfLongestIncreasingSequence(sequence, length);
	EXPECT_EQ(lengthOfLongestIncreasingSequence, 3);
}

TEST(LongestIncreasingSequenceTests, ThreeDecreasingItems)
{
	int sequence[3] = { 3, 2, 1 };
	int length = sizeof(sequence) / sizeof(sequence[0]);

	int lengthOfLongestIncreasingSequence = getLengthOfLongestIncreasingSequence(sequence, length);
	EXPECT_EQ(lengthOfLongestIncreasingSequence, 1);
}


TEST(LongestIncreasingSequenceTests, BookSequence)
{
	int sequence[9] = { 2, 4, 3, 5, 1, 7, 6, 9, 8 };
	int length = sizeof(sequence) / sizeof(sequence[0]);

	int lengthOfLongestIncreasingSequence = getLengthOfLongestIncreasingSequence(sequence, length);
	EXPECT_EQ(lengthOfLongestIncreasingSequence, 5);
}
