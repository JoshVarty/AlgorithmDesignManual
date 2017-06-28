#include "gtest/gtest.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
	string name;
	int score;
};

vector<Player> comparator(vector<Player> players) {
	return players;
}

TEST(ComparatorTests, Basic)
{
	vector<Player> players;
	
	Player p1;
	p1.name = "amy";
	p1.score = 100;
	players.push_back(p1);

	Player p2;
	p2.name = "david";
	p2.score = 100;
	players.push_back(p2);

	Player p3;
	p3.name = "heraldo";
	p3.score = 50;
	players.push_back(p3);

	Player p4;
	p4.name = "aakansha";
	p4.score = 75;
	players.push_back(p4);
	
	Player p5;
	p5.name = "aleksa";
	p5.score = 150;
	players.push_back(p5);

	EXPECT_EQ(players[0].name, "aleksa");
	EXPECT_EQ(players[1].name, "amy");
	EXPECT_EQ(players[2].name, "david");
	EXPECT_EQ(players[3].name, "aakansha");
	EXPECT_EQ(players[4].name, "heraldo");
	
	EXPECT_EQ(players[0].score, 150);
	EXPECT_EQ(players[1].score, 100);
	EXPECT_EQ(players[2].score, 100);
	EXPECT_EQ(players[3].score, 75);
	EXPECT_EQ(players[4].score, 50);
}
