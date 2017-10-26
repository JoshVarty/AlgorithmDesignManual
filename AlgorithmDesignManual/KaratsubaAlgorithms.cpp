#include "gtest/gtest.h"

using namespace std;


string RightPadWithZero(string input, int numZeros) {
	return string(numZeros, '0') + input;
}


string Add(string num1, string num2) {
	//Get the strings to be the same length
	int difference = abs(int(num1.length() - num2.length()));

	if (num1.length() < num2.length()) {
		num1 = RightPadWithZero(num1, difference);
	}
	else if (num2.length() < num1.length()) {
		num2 = RightPadWithZero(num2, difference);
	}

	string result = string(num1.length(), '0');
	//Add them up
	int carry = 0;
	for (int i = num1.length() - 1; i >= 0; i--) {
		int current1 = num1[i] - '0';
		int current2 = num2[i] - '0';

		int sum = current1 + current2 + carry;
		if (sum >= 10) {
			carry = 1;
			sum = sum - 10;
		}
		else {
			carry = 0;
		}

		result[i] = sum + '0';
	}

	//If there is a carry after all digit additions
	//then we have to resize the string and add the 1 to the left
	if (carry == 1) {
		result = string(1, '1') + result;
	}

	return result;
}

string KaratsubaMultiply(string num1, string num2) {

	if (num1.length() <= 2 && num2.length() <= 2) {
		int i1 = stoi(num1);
		int i2 = stoi(num2);
		if (i1 <= 10 || i2 <= 10) {
			return to_string(i1 * i2);
		}
	}

	/*string longerString = max(num1.length, num2.length);
	int middle = longerString.length() / 2;

	string high1 = num1.substr(0, num1.length() - middle + 1);
	string low1 = num1.substr(middle, num1.length() - middle + 1);
	string high2 = num2.substr(0, num2.length() - middle + 1);
	string low2 = num2.substr(middle, num2.length() - middle + 1);

	string z0 = KaratsubaMultiply(low1, low2);
	string a1 = Add(low1, high1);
	string a2 = Add(low2, high2);
	string z1 = KaratsubaMultiply(a1, a2);
	string z2 = KaratsubaMultiply(high1, high2);*/



	string result;
}


//TEST(KaratsubaTest, Basic) {
//	string num1 = "2";
//	string num2 = "2";
//	string result = KaratsubaMultiply(num1, num2);
//	EXPECT_EQ(result, "4");
//}


TEST(KaratsubaTest, Basic) {
	string num1 = "2";
	string num2 = "2";
	string result = Add(num1, num2);
	EXPECT_EQ(result, "4");
}

TEST(KaratsubaTest, BasicWithCarry) {
	string num1 = "19";
	string num2 = "19";
	string result = Add(num1, num2);
	EXPECT_EQ(result, "38");
}

TEST(KaratsubaTest, SizeIncreases) {
	string num1 = "99";
	string num2 = "99";
	string result = Add(num1, num2);
	EXPECT_EQ(result, "198");
}

TEST(KaratsubaTest, SlightlyDifferentLengths) {
	string num1 = "1";
	string num2 = "18";
	string result = Add(num1, num2);
	EXPECT_EQ(result, "19");
}

TEST(KaratsubaTest, SlightlyDifferentLengthsWithCarry) {
	string num1 = "9";
	string num2 = "19";
	string result = Add(num1, num2);
	EXPECT_EQ(result, "28");
}
