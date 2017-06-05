#include <iostream>

#include "gtest/gtest.h"
#include "StringReverser.h"

#pragma region ToLinkedListTests

TEST(StringReverserTests, OneWordString)
{
	std::string input = "Josh";
	std::string result = StringReverser::Reverse(input);

	EXPECT_EQ(result, "Josh");
}

#pragma endregion