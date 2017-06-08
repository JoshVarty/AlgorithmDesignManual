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

TEST(StringReverserTests, ThreeWordString)
{
	std::string input = "Josh is testing";
	std::string result = StringReverser::Reverse(input);

	EXPECT_EQ(result, "testing is Josh");
}
#pragma endregion