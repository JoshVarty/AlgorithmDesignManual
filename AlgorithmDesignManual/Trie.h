#pragma once
#include <string>
using namespace std;

class Trie {
public:
	int count = 0;			//number of items that have followed this path
	Trie * characters[26];	//my Trie only accepts lowercase english letters
	void Add(string input);
	int Find(string input);
};

