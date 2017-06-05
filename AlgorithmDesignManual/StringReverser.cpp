#include "StringReverser.h"
#include <string>

std::string StringReverser::Reverse(std::string input) {

	//First reverse the entire string
	int length = input.length();
	for (int i = 0; i < length / 2; i++) {
		char temp = input[i];
		input[i] = input[length - i - 1];
		input[length - i - 1] = temp;
	}

	//Secondly, reverse every word in the string

	return input;
}