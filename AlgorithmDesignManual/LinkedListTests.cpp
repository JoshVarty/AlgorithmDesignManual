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
	node->Insert(new LinkedList(2));

	std::string result = node->ToString();
	EXPECT_EQ(result, "1,2");
}

TEST(InsertTests, MultipleInsertTest)
{
	auto* node = new LinkedList(1);
	node->Insert(new LinkedList(2));
	node->Insert(new LinkedList(3));
	node->Insert(new LinkedList(4));
	node->Insert(new LinkedList(5));

	std::string result = node->ToString();
	EXPECT_EQ(result, "1,2,3,4,5");
}

#pragma endregion

#pragma region ReverseRecursionTests

TEST(InsertTests, ReverseRecursionOnSingleNode)
{
	auto* node = new LinkedList(1);

	std::string result = node->ToString();
	EXPECT_EQ(result, "1");

	auto* reversed = node->ReverseRecursion();

	result = reversed->ToString();
	EXPECT_EQ(result, "1");
}

TEST(InsertTests, ReverseRecursionCheckPointers)
{
	auto* node1 = new LinkedList(1);
	auto* node2 = new LinkedList(2);
	auto* node3 = new LinkedList(3);
	node1->Insert(node2);
	node1->Insert(node3);

	auto* reversed = node1->ReverseRecursion();
	auto result = reversed->ToString();
	EXPECT_EQ(result, "3,2,1");

	EXPECT_EQ(node3->next, node2);
	EXPECT_EQ(node2->next, node1);
	EXPECT_EQ(node1->next, nullptr);

	EXPECT_EQ(node3->prev, nullptr);
	EXPECT_EQ(node2->prev, node3);
	EXPECT_EQ(node1->prev, node2);
}

TEST(InsertTests, ReverseRecursionMultipleInsertTest)
{
	auto* node = new LinkedList(1);
	node->Insert(new LinkedList(2));
	node->Insert(new LinkedList(3));
	node->Insert(new LinkedList(4));
	node->Insert(new LinkedList(5));

	auto* reversed = node->ReverseRecursion();
	auto result = reversed->ToString();
	EXPECT_EQ(result, "5,4,3,2,1");
}

#pragma endregion

#pragma region ReverseNoRecursionTests

TEST(InsertTests, ReverseNoRecursionOnSingleNode)
{
	auto* node = new LinkedList(1);

	std::string result = node->ToString();
	EXPECT_EQ(result, "1");

	auto* reversed = node->ReverseNoRecursion();

	result = reversed->ToString();
	EXPECT_EQ(result, "1");
}

TEST(InsertTests, ReverseNoRecursionCheckPointers)
{
	auto* node1 = new LinkedList(1);
	auto* node2 = new LinkedList(2);
	auto* node3 = new LinkedList(3);
	node1->Insert(node2);
	node1->Insert(node3);

	auto* reversed = node1->ReverseNoRecursion();
	auto result = reversed->ToString();
	EXPECT_EQ(result, "3,2,1");

	EXPECT_EQ(node3->next, node2);
	EXPECT_EQ(node2->next, node1);
	EXPECT_EQ(node1->next, nullptr);

	EXPECT_EQ(node3->prev, nullptr);
	EXPECT_EQ(node2->prev, node3);
	EXPECT_EQ(node1->prev, node2);
}

TEST(InsertTests, ReverseNoRecursionMultipleInsertTest)
{
	auto* node = new LinkedList(1);
	node->Insert(new LinkedList(2));
	node->Insert(new LinkedList(3));
	node->Insert(new LinkedList(4));
	node->Insert(new LinkedList(5));

	auto* reversed = node->ReverseNoRecursion();
	auto result = reversed->ToString();
	EXPECT_EQ(result, "5,4,3,2,1");
}

#pragma endregion

#pragma region CycleDetectionTests


TEST(CycleDetectionTests, NoCycleOneNode)
{
	auto* node = new LinkedList(1);

	auto* cycle = node->FindNodeInCycle();
	EXPECT_EQ(cycle, nullptr);
}

TEST(CycleDetectionTests, NoCycleTwoNodes)
{
	auto* node = new LinkedList(1);
	node->Insert(new LinkedList(2));

	auto* cycle = node->FindNodeInCycle();
	EXPECT_EQ(cycle, nullptr);
}

TEST(CycleDetectionTests, NoCycleThreeNodes)
{
	auto* node = new LinkedList(1);
	node->Insert(new LinkedList(2));
	node->Insert(new LinkedList(3));

	auto* cycle = node->FindNodeInCycle();
	EXPECT_EQ(cycle, nullptr);
}

TEST(CycleDetectionTests, NoCycleTenNodes)
{
	auto* node = new LinkedList(1);
	node->Insert(new LinkedList(2));
	node->Insert(new LinkedList(3));
	node->Insert(new LinkedList(4));
	node->Insert(new LinkedList(5));
	node->Insert(new LinkedList(6));
	node->Insert(new LinkedList(7));
	node->Insert(new LinkedList(8));
	node->Insert(new LinkedList(9));
	node->Insert(new LinkedList(10));

	auto* reversed = node->FindNodeInCycle();
}
#pragma endregion

