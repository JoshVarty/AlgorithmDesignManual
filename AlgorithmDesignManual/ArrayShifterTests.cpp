#include <iostream>

#include "gtest/gtest.h"
#include "ArrayShifter.h"

#pragma region ArrayShifterTests

TEST(ArrayShifterTests, SingleItem)
{
	std::vector<int> input = { 1, };
	auto result = ArrayShifter::Shift(input, 1);

	EXPECT_EQ(result, result);
}

TEST(ArrayShifterTests, TwoItems_OneShift)
{
	std::vector<int> input = { 1, 2 };
	auto result = ArrayShifter::Shift(input, 1);

	EXPECT_EQ(result[0], 2);
	EXPECT_EQ(result[1], 1);
}

TEST(ArrayShifterTests, TwoItems_TwoShifts)
{
	std::vector<int> input = { 1, 2 };
	auto result = ArrayShifter::Shift(input, 2);

	EXPECT_EQ(result[0], 1);
	EXPECT_EQ(result[1], 2);
}


TEST(ArrayShifterTests, ThreeItems_TwoShifts)
{
	std::vector<int> input = { 1, 2, 3 };
	auto result = ArrayShifter::Shift(input, 2);

	EXPECT_EQ(result[0], 3);
	EXPECT_EQ(result[1], 2);
	EXPECT_EQ(result[2], 1);
}

TEST(ArrayShifterTests, ThreeItems_FiveShifts)
{
	std::vector<int> input = { 1, 2, 3 };
	auto result = ArrayShifter::Shift(input, 5);

	EXPECT_EQ(result[0], 2);
	EXPECT_EQ(result[1], 3);
	EXPECT_EQ(result[2], 1);
}

TEST(ArrayShifterTests, FiveItems_TwoShifts)
{
	std::vector<int> input = { 1, 2, 3, 4, 5};
	auto result = ArrayShifter::Shift(input, 5);

	EXPECT_EQ(result[0], 3);
	EXPECT_EQ(result[1], 4);
	EXPECT_EQ(result[2], 5);
	EXPECT_EQ(result[3], 1);
	EXPECT_EQ(result[4], 1);
}

#pragma endregion