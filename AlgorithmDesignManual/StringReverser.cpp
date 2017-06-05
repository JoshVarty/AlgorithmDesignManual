#include "StringReverser.h"
#include <string>

std::string StringReverser::Reverse(std::string input) {

	int length = input.length();
	for (int i = 0; i < input.length(); i++) {
		char temp = input[i];
		input[i] = input[length - i];
		input[length - i] = temp;
	}

}