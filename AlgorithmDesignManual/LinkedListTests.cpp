#include <iostream>

#include "gtest/gtest.h"
#include "LinkedList.h"

#pragma region InsertTests

TEST(InsertTests, BasicConstructionTest)
{
	auto* node = new LinkedList(1);

	std::string result = node->ToString();
	EXPECT_EQ(result, "1");
}

TEST(InsertTests, SingleInsertTest)
{
	auto* node = new LinkedList(1);
	node->Insert(2);

	std::string result = node->ToString();
	EXPECT_EQ(result, "1,2");
}

TEST(InsertTests, MultipleInsertTest)
{
	auto* node = new LinkedList(1);
	node->Insert(2);
	node->Insert(3);
	node->Insert(4);
	node->Insert(5);

	std::string result = node->ToString();
	EXPECT_EQ(result, "1,2,3,4,5");
}

#pragma endregion
