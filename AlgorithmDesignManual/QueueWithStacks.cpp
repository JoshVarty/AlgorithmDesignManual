#include "QueueWithStacks.h"


void QueueWithStacks::push(int item) {
	this->stack_newest_on_top.push(item);
}

void QueueWithStacks::pop() {

	if (!this->stack_oldest_on_top.empty()) {
		this->stack_oldest_on_top.pop();
	}
	else {
		while (!this->stack_newest_on_top.empty()) {
			auto current = stack_newest_on_top.top();
			stack_newest_on_top.pop();
			stack_oldest_on_top.push(current);
		}

		//Only pop if there's something to pop.
		//Not the end of the world if they try to pop an empty queue I guess...
		if (!stack_oldest_on_top.empty()) {
			stack_oldest_on_top.pop();
		}
	}
}


int QueueWithStacks::front() {
	if (!this->stack_oldest_on_top.empty()) {
		return this->stack_oldest_on_top.top();
	}
	else {
		while (!this->stack_newest_on_top.empty()) {
			auto current = stack_newest_on_top.top();
			stack_newest_on_top.pop();
			stack_oldest_on_top.push(current);
		}
	}

	return stack_oldest_on_top.top();
}