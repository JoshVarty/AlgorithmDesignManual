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

TEST(StringReverserTests, QuestionExample)
{
	std::string input = "My name is Chris";
	std::string result = StringReverser::Reverse(input);

	EXPECT_EQ(result, "Chris is name My");
}

TEST(StringReverserTests, BlankInput)
{
	std::string input = " ";
	std::string result = StringReverser::Reverse(input);

	EXPECT_EQ(result, " ");
}

TEST(StringReverserTests, MultipleSpaces)
{
	std::string input = "My  name   is  Josh";
	std::string result = StringReverser::Reverse(input);

	EXPECT_EQ(result, "Josh  is   name  My");
}
#pragma endregion