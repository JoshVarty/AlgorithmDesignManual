#include <iostream>

#include "gtest/gtest.h"

TEST(sample_test_case, sample_test)
{
	EXPECT_EQ(1, 1);
}

int main2(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar(); // keep console window open until Return keystroke
	return 0;
}