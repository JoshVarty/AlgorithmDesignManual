#include "ArrayShifter.h"


std::vector<int> ArrayShifter::Shift(std::vector<int> input, int numShifts) {

	int size = input.size();
	numShifts = numShifts % size;

	std::vector<int> temp(numShifts);
	for (int i = 0; i < numShifts; i++) {
		temp[i] = input[i];
	}

	for (int i = 0; i < size - numShifts; i++) {
		input[i] = input[i + numShifts];
	}

	for (int i = 0; i < numShifts; i++) {
		input[size - numShifts + i] = temp[i];
	}

	return input;
}