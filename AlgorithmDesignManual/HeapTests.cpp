#include "Heap.h"
#include "gtest/gtest.h"

#pragma region MinHeapTests

TEST(MinHeapTests, OneItemHeap)
{
	auto * heap = new MinHeap();
	heap->InsertItem(1);
	int result = heap->PopTopItem();
	
	EXPECT_EQ(result, 1);
}

TEST(MinHeapTests, FiveItemHeap)
{
	auto * heap = new MinHeap();
	heap->InsertItem(1);
	heap->InsertItem(2);
	heap->InsertItem(3);
	heap->InsertItem(4);
	heap->InsertItem(5);
	int firstMin = heap->PopTopItem();
	int secondMin = heap->PopTopItem();
	int thirdMin = heap->PopTopItem();
	int fourthMin = heap->PopTopItem();
	int fifthMin = heap->PopTopItem();
	
	EXPECT_EQ(firstMin, 1);
	EXPECT_EQ(secondMin, 2);
	EXPECT_EQ(thirdMin, 3);
	EXPECT_EQ(fourthMin, 4);
	EXPECT_EQ(fifthMin, 5);
}

TEST(MinHeapTests, FiveItemHeapWrongOrder)
{
	auto * heap = new MinHeap();
	heap->InsertItem(5);
	heap->InsertItem(4);
	heap->InsertItem(3);
	heap->InsertItem(2);
	heap->InsertItem(1);

	int firstMin = heap->PopTopItem();
	int secondMin = heap->PopTopItem();
	int thirdMin = heap->PopTopItem();
	int fourthMin = heap->PopTopItem();
	int fifthMin = heap->PopTopItem();
	
	EXPECT_EQ(firstMin, 1);
	EXPECT_EQ(secondMin, 2);
	EXPECT_EQ(thirdMin, 3);
	EXPECT_EQ(fourthMin, 4);
	EXPECT_EQ(fifthMin, 5);
}

#pragma endregion

#pragma region MaxHeapTests

TEST(MaxHeapTests, OneItemHeap)
{
	auto * heap = new MaxHeap();
	heap->InsertItem(1);
	int result = heap->PopTopItem();
	
	EXPECT_EQ(result, 1);
}

TEST(MaxHeapTests, FiveItemHeapWrongOrder)
{
	auto * heap = new MaxHeap();
	heap->InsertItem(1);
	heap->InsertItem(2);
	heap->InsertItem(3);
	heap->InsertItem(4);
	heap->InsertItem(5);
	int firstMin = heap->PopTopItem();
	int secondMin = heap->PopTopItem();
	int thirdMin = heap->PopTopItem();
	int fourthMin = heap->PopTopItem();
	int fifthMin = heap->PopTopItem();
	
	EXPECT_EQ(firstMin, 5);
	EXPECT_EQ(secondMin, 4);
	EXPECT_EQ(thirdMin, 3);
	EXPECT_EQ(fourthMin, 2);
	EXPECT_EQ(fifthMin, 1);
}

TEST(MaxHeapTests, FiveItemHeap)
{
	auto * heap = new MaxHeap();
	heap->InsertItem(5);
	heap->InsertItem(4);
	heap->InsertItem(3);
	heap->InsertItem(2);
	heap->InsertItem(1);
	int firstMin = heap->PopTopItem();
	int secondMin = heap->PopTopItem();
	int thirdMin = heap->PopTopItem();
	int fourthMin = heap->PopTopItem();
	int fifthMin = heap->PopTopItem();
	
	EXPECT_EQ(firstMin, 5);
	EXPECT_EQ(secondMin, 4);
	EXPECT_EQ(thirdMin, 3);
	EXPECT_EQ(fourthMin, 2);
	EXPECT_EQ(fifthMin, 1);
}

#pragma endregion
