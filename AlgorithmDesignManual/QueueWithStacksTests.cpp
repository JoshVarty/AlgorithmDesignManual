#include "gtest/gtest.h"
#include "QueueWithStacks.h"


using namespace std;


TEST(QueueWithStacksTests, InsertOneAndCheck)
{
	auto * queue = new QueueWithStacks();
	queue->push(1);

	int front = queue->front();
	EXPECT_EQ(front, 1);
}

TEST(QueueWithStacksTests, InsertTwoAndCheck)
{
	auto * queue = new QueueWithStacks();
	queue->push(1);
	queue->push(2);

	int front = queue->front();
	EXPECT_EQ(front, 1);
}

TEST(QueueWithStacksTests, InsertTwoPopAndCheck)
{
	auto * queue = new QueueWithStacks();
	queue->push(1);
	queue->push(2);
	queue->pop();

	int front = queue->front();
	EXPECT_EQ(front, 2);
}

TEST(QueueWithStacksTests, LongerTest)
{
	auto * queue = new QueueWithStacks();
	int front = -1;
	queue->push(42);
	queue->pop();
	queue->push(14);
	front = queue->front();
	EXPECT_EQ(front, 14);
	queue->push(28);
	front = queue->front();
	EXPECT_EQ(front, 14);
	queue->push(60);
	queue->push(78);
	queue->pop();
	queue->pop();
}
