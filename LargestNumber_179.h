#pragma once
#ifndef _LARGESTNUMBER_179_H_
#define _LARGESTNUMBER_179_H_ 

#include "ILeetCodeSolution.h"
#include <vector>
#include <string>


class LargestNumber_179 : public ILeetCodeSolution {
public:
	LargestNumber_179();
	LargestNumber_179(std::vector<int> num);
	void execute() override;
	std:: string result;
private:
	std::vector<int> numbers;
	std::string LargestNumber(std::vector<int> nums);
	static bool stringCmp(std::string s1, std::string s2);
};
#endif