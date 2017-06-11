#include "ArrayShifter.h"


std::vector<int> ArrayShifter::Shift(std::vector<int> input, int numShifts) {

	for (int j = 0; j < numShifts; j++) {

		int last = input[0];
		for (int i = input.size() - 1; i >= 0; i--) {
			int temp = input[i];
			input[i] = last;
			last = temp;
		}
	}
	return input;
}