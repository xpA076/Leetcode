#pragma once
/*
Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do NOT contain consecutive ones.

Example 1:
Input: 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule.
Note: 1 <= n <= 10¡ü9


*/


#ifndef _LEETCODE_H_
#define _LEETCODE_H_

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int findIntegers(int num) {
		vector<int> onePstn;
		int i;
		int flag = 1;
		int k;
		for (i = 0; i<30; ++i) {
			k = num & flag;
			if ((num&flag) != 0) {
				onePstn.push_back(i);
			}
			flag = flag << 1;
		}
		int countInt = 1;
		reverse(onePstn.begin(), onePstn.end());
		for (i = 0; i<(int)onePstn.size(); ++i) {
			// TO DO reverse
			countInt += Count(onePstn.at(i));
			if (i != 0 && (onePstn.at(i - 1) == onePstn.at(i) + 1)) {
				countInt--;
				break;
			}
		}
		return countInt;
	}

private:
	// Combination Defination (Mathematics)
	int C_(int a, int b)
	{
		long long val = 1;
		int i;
		for (i = 0; i<b; ++i) {
			val *= a - i;
		}
		for (i = 1; i <= b; ++i) {
			val /= i;
		}
		return (int)val;
	}
	// Count of Satisfying Integers less than bits
	// returns Fibonacci Sequence ( consider why~ )
	int Count(int bits) {
		int i;
		int count = 0;
		for (i = 0; i <= (bits + 1) / 2; ++i) {
			count += C_(bits + 1 - i, i);
		}
		return count;
	}
};






#endif // !_LEETCODE_H_
