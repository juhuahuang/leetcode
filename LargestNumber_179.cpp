#include "LargestNumber_179.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

LargestNumber_179::LargestNumber_179() {
	cout << "executing Leetcode problem 179 largest number" << endl;
	int arraySize = 10;
	int randNum;
	cout << "input numbers" << endl;
	for (int i = 0; i < arraySize; ++i) {
		randNum = rand() % 100 + 1;
		cout << randNum << " ";
		this->numbers.push_back(rand() % 100 + 1);
	}
	cout << endl;
}

LargestNumber_179::LargestNumber_179(vector<int> numbers) {
	cout << "executing Leetcode problem 179 largest number" << endl;
	this->numbers = numbers;
}

void LargestNumber_179::execute() {
	this->result = this->LargestNumber(this->numbers);
	cout << this->result << endl;
}

string LargestNumber_179::LargestNumber(vector<int> nums)
{
	vector<string> stringNumbers;
	bool hasPositive = false;
	for (int n : nums) {
		if (n > 0) {
			hasPositive = true;
		}
		stringNumbers.push_back(to_string(n));
	}
	if (!hasPositive) {
		return "0";
	}
	sort(stringNumbers.begin(), stringNumbers.end(), stringCmp);
	string result;
	for (string s : stringNumbers) {
		result += s;
	}
	return result;
}

bool LargestNumber_179::stringCmp(string s1, string s2)
{
	string::iterator s1Iter = s1.begin();
	string::iterator s2Iter = s2.begin();
	while (s1Iter != s1.end() && s2Iter != s2.end()) {
		if (*s1Iter != *s2Iter) {
			return *s1Iter > *s2Iter;
		}
		s1Iter++;
		s2Iter++;
	}

	return s1 + s2 > s2 + s1;
}
