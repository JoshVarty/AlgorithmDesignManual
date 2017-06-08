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
		for (j = i; j < length; j++) {
			if (input[j] == ' ') {
				break;
			}
		}
		
		for (int k = 0; k < (j - i) / 2; k++) {
			char temp = input[i + k];
			input[i + k] = input[j - k - 1];
			input[j - k - 1] = temp;
		}

		i = i + (j - i) + 1;
	}

	return input;
}