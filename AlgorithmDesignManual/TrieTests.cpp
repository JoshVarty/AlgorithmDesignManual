#include <iostream>

#include "gtest/gtest.h"
#include "Trie.h"

#pragma region TrieTests

TEST(TrieTests, EmptyTrie)
{
	auto *trie = new Trie();
	auto result = trie->Find("josh");

	EXPECT_EQ(result, 0);
}

TEST(TrieTests, OneItemPerfectMatch)
{
	auto *trie = new Trie();
	trie->Add("josh");

	auto result = trie->Find("josh");

	EXPECT_EQ(result, 1);
}

TEST(TrieTests, OneItemImperfectMatch)
{
	auto *trie = new Trie();
	trie->Add("josh");

	auto result = trie->Find("j");

	EXPECT_EQ(result, 1);
}

TEST(TrieTests, TwoItemsPerfectMatch)
{
	auto *trie = new Trie();
	trie->Add("josh");
	trie->Add("Varty");

	auto result = trie->Find("josh");

	EXPECT_EQ(result, 1);
}

TEST(TrieTests, TwoItemsImperfectMatch)
{
	auto *trie = new Trie();
	trie->Add("josh");
	trie->Add("varty");

	auto result = trie->Find("var");

	EXPECT_EQ(result, 1);
}

#pragma endregion
