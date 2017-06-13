#include "Trie.h"
#include <iostream>
using namespace std;

void Trie::Add(string input) {
	this->count = this->count + 1;
	
	if (input.length() <= 0) {
		return;
	}

	char leadingChar = input[0];
	int index = leadingChar - 'a';
	
	if (this->characters[index] == nullptr) {
		this->characters[index] = new Trie();
	}

	std::string remainder = input.substr(1, input.length() - 1);
	this->characters[index]->Add(remainder);
}

int Trie::Find(string input) {
	
	if (input.length() <= 0) {
		return this->count;
	}

	char leadingChar = input[0];
	int index = leadingChar - 'a';
	
	if (this->characters[index] != nullptr) {
		std::string remainder = input.substr(1, input.length() - 1);
		this->characters[index]->Find(remainder);
	}
	else {
		return 0;
	}
}