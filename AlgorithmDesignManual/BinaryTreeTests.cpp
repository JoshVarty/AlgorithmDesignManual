#include <iostream>

#include "gtest/gtest.h"
#include "BinaryTree.h"

TEST(InsertTest, SingleInsertTest)
{
	auto* root = new BinaryTree(1);

	std::string result = root->ToString();
	result.erase(0, 1);

	EXPECT_EQ(result, "1");
}

TEST(InsertTest, BasicInsertTest)
{
	auto* root = new BinaryTree(1);
	root->Insert(new BinaryTree(2));
	root->Insert(new BinaryTree(3));

	std::string result = root->ToString();
	result.erase(0, 1);

	EXPECT_EQ(result, "1,2,3");
}

TEST(InsertTest, InsertMultipleSameKeyTest)
{
	auto* root = new BinaryTree(2);
	root->Insert(new BinaryTree(3));
	root->Insert(new BinaryTree(1));
	root->Insert(new BinaryTree(1));
	root->Insert(new BinaryTree(1));

	std::string result = root->ToString();
	result.erase(0, 1);

	EXPECT_EQ(result, "1,1,1,2,3");
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar(); // keep console window open until Return keystroke
	return 0;
}