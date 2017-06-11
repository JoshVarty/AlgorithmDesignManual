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

	EXPECT_EQ(result, result);
}

TEST(ArrayShifterTests, TwoItems_TwoShifts)
{
	std::vector<int> input = { 1, 2 };
	auto result = ArrayShifter::Shift(input, 2);

	EXPECT_EQ(result, result);
}


TEST(ArrayShifterTests, ThreeItems_TwoShifts)
{
	std::vector<int> input = { 1, 2, 3 };
	auto result = ArrayShifter::Shift(input, 2);

	EXPECT_EQ(result, result);
}

TEST(ArrayShifterTests, ThreeItems_FiveShifts)
{
	std::vector<int> input = { 1, 2, 3 };
	auto result = ArrayShifter::Shift(input, 5);

	EXPECT_EQ(result, result);
}

TEST(ArrayShifterTests, FiveItems_TwoShifts)
{
	std::vector<int> input = { 1, 2, 3, 4, 5};
	auto result = ArrayShifter::Shift(input, 5);

	EXPECT_EQ(result, result);
}
#pragma endregion