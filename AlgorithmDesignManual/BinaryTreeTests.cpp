#include <iostream>

#include "gtest/gtest.h"
#include "BinaryTree.h"

#pragma region InsertTests

TEST(InsertTest, SingleInsertTest)
{
	auto* root = new BinaryTree(1);

	std::string result = root->ToString();
	EXPECT_EQ(result, "1");
}

TEST(InsertTest, BasicInsertTest)
{
	auto* root = new BinaryTree(1);
	root->Insert(new BinaryTree(2));
	root->Insert(new BinaryTree(3));

	std::string result = root->ToString();
	EXPECT_EQ(result, "1,2,3");
}

TEST(InsertTest, MoreInserts)
{
	auto* root = new BinaryTree(9);
	root->Insert(new BinaryTree(3));
	root->Insert(new BinaryTree(2));
	root->Insert(new BinaryTree(4));
	root->Insert(new BinaryTree(1));
	root->Insert(new BinaryTree(6));
	root->Insert(new BinaryTree(7));
	root->Insert(new BinaryTree(8));
	root->Insert(new BinaryTree(5));

	std::string result = root->ToString();
	EXPECT_EQ(result, "1,2,3,4,5,6,7,8,9");
}

TEST(InsertTest, InsertMultipleSameKeyTest)
{
	auto* root = new BinaryTree(2);
	root->Insert(new BinaryTree(3));
	root->Insert(new BinaryTree(1));
	root->Insert(new BinaryTree(1));
	root->Insert(new BinaryTree(1));

	std::string result = root->ToString();
	EXPECT_EQ(result, "1,1,1,2,3");
}

#pragma endregion

#pragma region FindTests

TEST(FindTest, FindAfterInesrtInOrder)
{
	auto* root = new BinaryTree(1);
	root->Insert(new BinaryTree(2));
	root->Insert(new BinaryTree(3));

	auto* min = root->FindMinimum();
	EXPECT_EQ(min->item, 1);
}

TEST(FindTest, FindAfterInesrtInReverseOrder)
{
	auto* root = new BinaryTree(3);
	root->Insert(new BinaryTree(2));
	root->Insert(new BinaryTree(1));

	auto* min = root->FindMinimum();
	EXPECT_EQ(min->item, 1);
}

TEST(FindTest, FindAfterInsertAllIdentical)
{
	auto* root = new BinaryTree(1);
	root->Insert(new BinaryTree(1));
	root->Insert(new BinaryTree(1));
	root->Insert(new BinaryTree(1));
	root->Insert(new BinaryTree(1));

	auto* min = root->FindMinimum();
	EXPECT_EQ(min->item, 1);
}

#pragma endregion

#pragma region SearchTests

TEST(SearchTest, BasicSearch)
{
	auto* root = new BinaryTree(1);
	auto* searchItem = root->SearchTree(1);

	EXPECT_EQ(searchItem->item, 1);
}

TEST(SearchTest, SearchNotInTree)
{
	auto* root = new BinaryTree(1);
	auto* searchItem = root->SearchTree(2);

	EXPECT_EQ(searchItem, nullptr);
}

TEST(SearchTest, SearchThreeItems)
{
	auto* root = new BinaryTree(1);
	root->Insert(new BinaryTree(2));
	root->Insert(new BinaryTree(3));

	auto* searchItem = root->SearchTree(1);
	EXPECT_EQ(searchItem->item, 1);
	searchItem = root->SearchTree(2);
	EXPECT_EQ(searchItem->item, 2);
	searchItem = root->SearchTree(3);
	EXPECT_EQ(searchItem->item, 3);
}

TEST(SearchTest, SearchOneHundredItems)
{
	auto* root = new BinaryTree(1);

	for (int i = 2; i < 100; i++) {
		root->Insert(new BinaryTree(i));
	}

	for (int i = 1; i < 100; i++) {
		auto* searchItem = root->SearchTree(i);
		EXPECT_EQ(searchItem->item, i);
	}

	auto* searchItem = root->SearchTree(1);
	EXPECT_EQ(searchItem->item, 1);
	searchItem = root->SearchTree(2);
	EXPECT_EQ(searchItem->item, 2);
	searchItem = root->SearchTree(3);
	EXPECT_EQ(searchItem->item, 3);
}

#pragma endregion

#pragma region IdenticalTests

TEST(IdenticalTests, BasicTest)
{
	auto* firstRoot = new BinaryTree(1);
	auto* secondRoot = new BinaryTree(1);

	bool result = firstRoot->IsIdentical(secondRoot);
	EXPECT_TRUE(result, true);
}

TEST(IdenticalTests, IdenticalThreeElements)
{
	auto* firstRoot = new BinaryTree(1);
	firstRoot->Insert(new BinaryTree(2));
	firstRoot->Insert(new BinaryTree(3));

	auto* secondRoot = new BinaryTree(1);
	secondRoot->Insert(new BinaryTree(2));
	secondRoot->Insert(new BinaryTree(3));

	bool result = firstRoot->IsIdentical(secondRoot);
	EXPECT_TRUE(result);
}

TEST(IdenticalTests, NotIdenticalTest_ExtraElement)
{
	auto* firstRoot = new BinaryTree(1);
	firstRoot->Insert(new BinaryTree(2));

	auto* secondRoot = new BinaryTree(1);

	bool result = firstRoot->IsIdentical(secondRoot);
	EXPECT_FALSE(result);
}

TEST(IdenticalTests, NotIdenticalTest_ExtraElement2)
{
	auto* firstRoot = new BinaryTree(1);

	auto* secondRoot = new BinaryTree(1);
	secondRoot->Insert(new BinaryTree(2));

	bool result = firstRoot->IsIdentical(secondRoot);
	EXPECT_FALSE(result);
}

TEST(IdenticalTests, NotIdenticalTest_DifferentRoots)
{
	auto* firstRoot = new BinaryTree(1);

	auto* secondRoot = new BinaryTree(2);

	bool result = firstRoot->IsIdentical(secondRoot);
	EXPECT_FALSE(result);
}

TEST(IdenticalTests, NotIdenticalTest_DifferentOrder)
{
	auto* firstRoot = new BinaryTree(3);
	firstRoot->Insert(new BinaryTree(2));
	firstRoot->Insert(new BinaryTree(1));

	auto* secondRoot = new BinaryTree(1);
	secondRoot->Insert(new BinaryTree(2));
	secondRoot->Insert(new BinaryTree(3));

	bool result = firstRoot->IsIdentical(secondRoot);
	EXPECT_FALSE(result);
}

#pragma endregion

#pragma region ToLinkedListTests

TEST(LinkedListTests, SingleItem)
{
	auto* root = new BinaryTree(3);
	auto* list = root->ToLinkedList();
	EXPECT_EQ(root->ToString(), list->ToString());
}

TEST(LinkedListTests, InsertTwoItems)
{
	auto* root = new BinaryTree(3);
	root->Insert(new BinaryTree(2));
	root->Insert(new BinaryTree(1));

	auto* list = root->ToLinkedList();
	EXPECT_EQ(root->ToString(), list->ToString());
}

TEST(LinkedListTests, InsertTwoItemsDifferentOrder)
{
	auto* root = new BinaryTree(2);
	root->Insert(new BinaryTree(3));
	root->Insert(new BinaryTree(1));

	auto* list = root->ToLinkedList();
	EXPECT_EQ(root->ToString(), list->ToString());
}

TEST(LinkedListTests, InsertManyItems)
{
	auto* root = new BinaryTree(3);
	root->Insert(new BinaryTree(2));
	root->Insert(new BinaryTree(1));
	root->Insert(new BinaryTree(8));
	root->Insert(new BinaryTree(9));
	root->Insert(new BinaryTree(3));
	root->Insert(new BinaryTree(4));
	root->Insert(new BinaryTree(10));
	root->Insert(new BinaryTree(4));

	auto* list = root->ToLinkedList();
	EXPECT_EQ(root->ToString(), list->ToString());
}

#pragma endregion

#pragma region IsValidBinaryTreeTests

TEST(IsValidBinaryTreeTests, ValidTreeOneItem)
{
	auto* root = new BinaryTree(3);

	bool isValidBinaryTree = root->IsValidBinaryTree();
	EXPECT_TRUE(isValidBinaryTree);
}

TEST(IsValidBinaryTreeTests, ValidTreeThreeItems)
{
	auto* root = new BinaryTree(3);
	root->Insert(new BinaryTree(2));
	root->Insert(new BinaryTree(1));

	bool isValidBinaryTree = root->IsValidBinaryTree();
	EXPECT_TRUE(isValidBinaryTree);
}

TEST(IsValidBinaryTreeTests, ValidTreeTenItems)
{
	auto* root = new BinaryTree(3);
	root->Insert(new BinaryTree(2));
	root->Insert(new BinaryTree(1));
	root->Insert(new BinaryTree(8));
	root->Insert(new BinaryTree(9));
	root->Insert(new BinaryTree(3));
	root->Insert(new BinaryTree(4));
	root->Insert(new BinaryTree(10));
	root->Insert(new BinaryTree(4));

	bool isValidBinaryTree = root->IsValidBinaryTree();
	EXPECT_TRUE(isValidBinaryTree);
}

TEST(IsValidBinaryTreeTests, BadTreeTwoItems)
{
	auto* root = new BinaryTree(1);
	root->left = new BinaryTree(2);

	bool isValidBinaryTree = root->IsValidBinaryTree();
	EXPECT_FALSE(isValidBinaryTree);
}

TEST(IsValidBinaryTreeTests, BadTreeTwoItems2)
{
	auto* root = new BinaryTree(2);
	root->right = new BinaryTree(1);

	bool isValidBinaryTree = root->IsValidBinaryTree();
	EXPECT_FALSE(isValidBinaryTree);
}

TEST(IsValidBinaryTreeTests, BadTreeTenItems)
{
	auto* root = new BinaryTree(3);
	root->Insert(new BinaryTree(2));
	root->Insert(new BinaryTree(1));
	root->Insert(new BinaryTree(8));
	root->Insert(new BinaryTree(9));
	root->Insert(new BinaryTree(3));
	root->Insert(new BinaryTree(4));
	root->Insert(new BinaryTree(10));
	auto node = new BinaryTree(4);
	root->Insert(node);
	node->right = new BinaryTree(1);

	bool isValidBinaryTree = root->IsValidBinaryTree();
	EXPECT_FALSE(isValidBinaryTree);
}

TEST(IsValidBinaryTreeTests, BadTreeTenItems2)
{
	auto* root = new BinaryTree(3);
	root->Insert(new BinaryTree(2));
	root->Insert(new BinaryTree(1));
	root->Insert(new BinaryTree(8));
	root->Insert(new BinaryTree(9));
	root->Insert(new BinaryTree(3));
	root->Insert(new BinaryTree(4));
	root->Insert(new BinaryTree(10));
	auto node = new BinaryTree(4);
	root->Insert(node);
	node->left = new BinaryTree(10);

	bool isValidBinaryTree = root->IsValidBinaryTree();
	EXPECT_FALSE(isValidBinaryTree);
}

#pragma endregion


int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar(); // keep console window open until Return keystroke
	return 0;
}