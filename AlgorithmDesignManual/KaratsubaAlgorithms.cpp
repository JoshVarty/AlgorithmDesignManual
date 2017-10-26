#include "gtest/gtest.h"

using namespace std;


string LeftPadWithZero(string input, int numZeros) {
	return string(numZeros, '0') + input;
}

string RightPadWithZero(string input, int numZeros) {
	return input + string(numZeros, '0');
}

//Returns num1 + num2
string Add(string num1, string num2) {
	//Get the strings to be the same length
	int difference = abs(int(num1.length() - num2.length()));

	if (num1.length() < num2.length()) {
		num1 = LeftPadWithZero(num1, difference);
	}
	else if (num2.length() < num1.length()) {
		num2 = LeftPadWithZero(num2, difference);
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

//Returns num1 - num2
//Requires: num1 >= num2
string Substract(string num1, string num2) {

	//make sure they're the same length
	int difference = abs(int(num1.length() - num2.length()));

	if (num1.length() < num2.length()) {
		num1 = LeftPadWithZero(num1, difference);
	}
	else if (num2.length() < num1.length()) {
		num2 = LeftPadWithZero(num2, difference);
	}

	string result = string(num1.length(), '0');
	int carry = 0;
	for (int i = num1.length() - 1; i >= 0; i--) {
		int current1 = num1[i] - '0';
		int current2 = num2[i] - '0';

		if (current2 > current1) {
			current1 = current1 + 10;

			int j = i - 1;
			while (j >= 0) {
				num1[j] = (num1[j] - '0') - 1 % 10 + '0';
				//Only keep going if we've wrapped from 0 to 9
				if (num1[j] != '9')
					break;

				j--;
			}

		}

		result[i] = (current1 - current2) + '0';
	}

	//Remove any leading zeros. 
	//However if it's all zeros, don't remove all of them.
	int i = 0;
	while (result[i] == '0' && i < result.length() - 1) {
		i++;
	}

	result.erase(0, i);
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

	//Get the strings to be the same length
	int difference = abs(int(num1.length() - num2.length()));

	if (num1.length() < num2.length()) {
		num1 = LeftPadWithZero(num1, difference);
	}
	else if (num2.length() < num1.length()) {
		num2 = LeftPadWithZero(num2, difference);
	}

	int maxLength = max(num1.length(), num2.length());
	int c_middle = (maxLength + 1) / 2;
	int middle = maxLength / 2;

	string xLeft = num1.substr(0, c_middle);
	string xRight = num1.substr(c_middle, num1.length() - c_middle);
	string yLeft = num2.substr(0, c_middle);
	string yRight = num2.substr(c_middle, num2.length() - c_middle);

	string z0 = KaratsubaMultiply(xRight, yRight);
	string z1 = KaratsubaMultiply(Add(xRight, xLeft), Add(yRight, yLeft));
	string z2 = KaratsubaMultiply(xLeft, yLeft);

	string a1 = RightPadWithZero(z2, 2 * (middle));
	string a2 = RightPadWithZero(Substract(Substract(z1, z2), z0), middle);

	string result = Add(Add(a1, a2), z0);
	return result;
}


TEST(KaratsubaTest, Basic) {
	string num1 = "2";
	string num2 = "2";
	string result = KaratsubaMultiply(num1, num2);
	EXPECT_EQ(result, "4");
}

TEST(KaratsubaTest, BasicWithExpansion) {
	string num1 = "9";
	string num2 = "9";
	string result = KaratsubaMultiply(num1, num2);
	EXPECT_EQ(result, "81");
}


TEST(KaratsubaTest, TwoDigits) {
	string num1 = "99";
	string num2 = "99";
	string result = KaratsubaMultiply(num1, num2);
	EXPECT_EQ(result, "9801");
}

TEST(KaratsubaTest, ThreeDigits) {
	string num1 = "100";
	string num2 = "100";
	string result = KaratsubaMultiply(num1, num2);
	EXPECT_EQ(result, "10000");
}


TEST(KaratsubaTest, ThreeDigits2) {
	string num1 = "198";
	string num2 = "198";
	string result = KaratsubaMultiply(num1, num2);
	EXPECT_EQ(result, "39204");
}

TEST(KaratsubaTest, ThreeDigits3) {
	string num1 = "117";
	string num2 = "117";
	string result = KaratsubaMultiply(num1, num2);
	EXPECT_EQ(result, "13689");
}

TEST(KaratsubaTest, UnevenDigits) {
	string num1 = "12345";
	string num2 = "6789";
	string result = KaratsubaMultiply(num1, num2);
	EXPECT_EQ(result, "83810205");
}



TEST(KaratsubaAddTest, BasicWithCarry) {
	string num1 = "19";
	string num2 = "19";
	string result = Add(num1, num2);
	EXPECT_EQ(result, "38");
}

TEST(KaratsubaAddTest, SizeIncreases) {
	string num1 = "99";
	string num2 = "99";
	string result = Add(num1, num2);
	EXPECT_EQ(result, "198");
}

TEST(KaratsubaAddTest, SlightlyDifferentLengths) {
	string num1 = "1";
	string num2 = "18";
	string result = Add(num1, num2);
	EXPECT_EQ(result, "19");
}

TEST(KaratsubaAddTest, SlightlyDifferentLengthsWithCarry) {
	string num1 = "9";
	string num2 = "19";
	string result = Add(num1, num2);
	EXPECT_EQ(result, "28");
}



TEST(KaratsubaSubTest, Basic) {
	string num1 = "5";
	string num2 = "3";
	string result = Substract(num1, num2);
	EXPECT_EQ(result, "2");
}

TEST(KaratsubaSubTest, BasicZeroSum) {
	string num1 = "19";
	string num2 = "19";
	string result = Substract(num1, num2);
	EXPECT_EQ(result, "0");
}

TEST(KaratsubaSubTest, MultipleCarries) {
	string num1 = "100";
	string num2 = "1";
	string result = Substract(num1, num2);
	EXPECT_EQ(result, "99");
}

TEST(KaratsubaSubTest, MultipleCarries2) {
	string num1 = "100";
	string num2 = "99";
	string result = Substract(num1, num2);
	EXPECT_EQ(result, "1");
}