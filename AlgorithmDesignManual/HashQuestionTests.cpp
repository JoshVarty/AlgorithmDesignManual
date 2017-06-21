#include "gtest/gtest.h"
#include <string>
#include <unordered_map>

using namespace std;

template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

bool canDoIt(string a, string b) {
	
	unordered_map<string, int> hashTable = { };
	auto splitA = split(a, ' ');
	auto splitB = split(b, ' ');

	for (int i = 0; i < splitA.size(); i++) {
		string word = splitA[i];
		hashTable[word] = hashTable[word] + 1;
	}

	for (int i = 0; i < splitB.size(); i++) {
		string word = splitB[i];
		int result = hashTable[word];
		if (result <= 0) {
			return false;
		}
	}

	return true;
}

TEST(HashQuestionsTests, SingleWordExists)
{
	string a = "word";
	string b = "word";
	bool canCreateSentence = canDoIt(a, b);

	EXPECT_TRUE(canCreateSentence);
}

TEST(HashQuestionsTests, SingleWordDoesNotExist)
{
	string a = "word";
	string b = "someOtherWord";
	bool canCreateSentence = canDoIt(a, b);

	EXPECT_FALSE(canCreateSentence);
}
