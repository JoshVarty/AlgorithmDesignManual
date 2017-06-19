#include "gtest/gtest.h"
#include <string>

using namespace std;

int number_needed(string a, string b) {
	int letters[26] = { 0 };
	for (int i = 0; i < a.length(); i++) {
		int index = a[i] - 'a';
		letters[index] = letters[index] + 1;
	}

	for (int i = 0; i < b.length(); i++) {
		int index = b[i] - 'a';
		letters[index] = letters[index] - 1;
	}

	int numChanges = 0;
	for (int i = 0; i < 26; i++) {
		numChanges = numChanges + abs(letters[i]);
	}

	return numChanges;
}


TEST(AnagramsTests, BasicTest)
{
	string a = "cde";
	string b = "abc";
	int numNeeded = number_needed(a, b);

	EXPECT_EQ(numNeeded, 4);
}

