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

	if (input.length() <= 1) {
		return;
	}

	std::string remainder = input.substr(1, input.length() - 1);
	this->characters[index]->Add(remainder);
}

int Trie::Find(string input) {
	return -1;
}