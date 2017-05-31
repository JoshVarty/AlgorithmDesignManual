#include <iostream>

#include "gtest/gtest.h"
#include "BinaryTree.h"

TEST(sample_test_case, sample_test)
{
	auto* root = new BinaryTree(2);
	
	auto* newNode = new BinaryTree(3);
	auto* newNode2 = new BinaryTree(1);
	root->Insert(newNode);
	root->Insert(newNode2);

	EXPECT_EQ(1, 1);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar(); // keep console window open until Return keystroke
	return 0;
}