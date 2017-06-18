#include "MedianTracker.h"
#include "gtest/gtest.h"

#pragma region MedianTrackerTests


TEST(MediaTrackerTests, InsertOneItem)
{
	auto* tracker = new MedianTracker();
	int median = tracker->AddItem(1);
	EXPECT_EQ(median, 1);
}


TEST(MedianTrackerTests, ItemsIncreasing)
{
	auto* tracker = new MedianTracker();
	double median1 = tracker->AddItem(1);
	double median2 = tracker->AddItem(2);
	double median3 = tracker->AddItem(3);
	double median4 = tracker->AddItem(4);
	double median5 = tracker->AddItem(5);

	EXPECT_EQ(median1, 1.0);
	EXPECT_EQ(median2, 1.5);
	EXPECT_EQ(median3, 2.0);
	EXPECT_EQ(median4, 2.5);
	EXPECT_EQ(median5, 3.0);
}

TEST(MedianTrackerTests, ItemsDencreasing)
{
	auto* tracker = new MedianTracker();
	double median1 = tracker->AddItem(5);
	double median2 = tracker->AddItem(4);
	double median3 = tracker->AddItem(3);
	double median4 = tracker->AddItem(2);
	double median5 = tracker->AddItem(1);

	EXPECT_EQ(median1, 5.0);
	EXPECT_EQ(median2, 4.5);
	EXPECT_EQ(median3, 4.0);
	EXPECT_EQ(median4, 3.5);
	EXPECT_EQ(median5, 3.0);
}

#pragma endregion

