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
	int i = 0; 
	while (i < length)
	{
		int j;
		for (j = i; j < length - 1; j++) {
			if (input[j] == ' ') {
				break;
			}
		}

		for (int k = 0; k <= j / 2; k++) {
			char temp = input[i + k];
			input[i + k] = input[j - k];
			input[j - k] = temp;
		}

		i = i + j + 1;
	}

	return input;
}