#include <iostream>

#include "gtest/gtest.h"
#include "Trie.h"

#pragma region TrieTests

TEST(TrieTests, EmptyTrie)
{
	auto *trie = new Trie();
	auto result = trie->Find("Josh");

	EXPECT_EQ(result, 0);
}

TEST(TrieTests, OneItemPerfectMatch)
{
	auto *trie = new Trie();
	trie->Add("Josh");

	auto result = trie->Find("Josh");

	EXPECT_EQ(result, 1);
}

TEST(TrieTests, OneItemImperfectMatch)
{
	auto *trie = new Trie();
	trie->Add("Josh");

	auto result = trie->Find("J");

	EXPECT_EQ(result, 1);
}

TEST(TrieTests, TwoItemsPerfectMatch)
{
	auto *trie = new Trie();
	trie->Add("Josh");
	trie->Add("Varty");

	auto result = trie->Find("Josh");

	EXPECT_EQ(result, 1);
}

TEST(TrieTests, TwoItemsImperfectMatch)
{
	auto *trie = new Trie();
	trie->Add("Josh");
	trie->Add("Varty");

	auto result = trie->Find("Var");

	EXPECT_EQ(result, 1);
}

#pragma endregion
