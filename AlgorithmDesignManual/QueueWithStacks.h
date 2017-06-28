#pragma once

#include <stack>
using namespace std;

class QueueWithStacks {
public:
	stack<int> stack_newest_on_top;
	stack<int> stack_oldest_on_top;

	void push(int item);
	void pop();
	int front();
};
