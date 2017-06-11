#include <iostream>

#include "gtest/gtest.h"
#include "ArrayShifter.h"

#pragma region ArrayShifterTests

TEST(ArrayShifterTests, SingleItem)
{
	std::vector<int> input = { 1, };
	auto result = ArrayShifter::Shift(input, 1, 1);

	EXPECT_EQ(result, result);
}

#pragma endregion