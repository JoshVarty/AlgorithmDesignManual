#include "gtest/gtest.h"
#include <string>

using namespace std;

int getMinimumNumberOfCoins(int coins[], int coinsLength, int target)
{
	vector<int> minCoins(target + 1);

	for (int i = 1; i <= target; i++) {

		int currentMin = INT_MAX / 2;
		for (int j = 0; j < coinsLength; j++) {

			int index = i - coins[j];
			if (index < 0) {
				continue;
			}

			if (currentMin > minCoins[index] + 1) {
				currentMin = minCoins[index] + 1;
			}
		}

		minCoins[i] = currentMin;
	}

	return minCoins[target];
}

TEST(NumCoinsTests, Test1)
{
	int coinsAvailable[] = { 1, 5, 12, 25 };
	int coinsLength = sizeof(coinsAvailable) / sizeof(coinsAvailable[0]);
	int target = 16;

	int minNum = getMinimumNumberOfCoins(coinsAvailable, coinsLength, target);

	EXPECT_EQ(minNum, 4);
}

TEST(NumCoinsTests, Test2)
{
	int coinsAvailable[] = { 25, 10, 5 };
	int coinsLength = sizeof(coinsAvailable) / sizeof(coinsAvailable[0]);
	int target = 30;

	int minNum = getMinimumNumberOfCoins(coinsAvailable, coinsLength, target);

	EXPECT_EQ(minNum, 2);
}


TEST(NumCoinsTests, Test3)
{
	int coinsAvailable[] = { 9, 6, 5, 1 };
	int coinsLength = sizeof(coinsAvailable) / sizeof(coinsAvailable[0]);
	int target = 11;

	int minNum = getMinimumNumberOfCoins(coinsAvailable, coinsLength, target);

	EXPECT_EQ(minNum, 2);
}
