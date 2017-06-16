#include "Heap.h"
#include "gtest/gtest.h"

#pragma region MinHeapTests

TEST(MinHeapTests, OneItemHeap)
{
	auto * heap = new MinHeap();
	heap->InsertItem(1);
	int result = heap->GetTopItem();
	
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
	int result = heap->GetTopItem();
	
	EXPECT_EQ(result, 1);
}

TEST(MinHeapTests, FiveItemHeapWrongOrder)
{
	auto * heap = new MinHeap();
	heap->InsertItem(5);
	heap->InsertItem(4);
	heap->InsertItem(3);
	heap->InsertItem(2);
	heap->InsertItem(1);
	int result = heap->GetTopItem();
	
	EXPECT_EQ(result, 1);
}

#pragma endregion

#pragma region MaxHeapTests

TEST(MaxHeapTests, OneItemHeap)
{
	auto * heap = new MaxHeap();
	heap->InsertItem(1);
	int result = heap->GetTopItem();
	
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
	int result = heap->GetTopItem();
	
	EXPECT_EQ(result, 5);
}

TEST(MaxHeapTests, FiveItemHeap)
{
	auto * heap = new MaxHeap();
	heap->InsertItem(5);
	heap->InsertItem(4);
	heap->InsertItem(3);
	heap->InsertItem(2);
	heap->InsertItem(1);
	int result = heap->GetTopItem();
	
	EXPECT_EQ(result, 5);
}

#pragma endregion
