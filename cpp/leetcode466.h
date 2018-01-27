#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>


using namespace std;
class Solution {
public:
	int getMaxRepetitions(string s1, int n1, string s2, int n2) {
		int *C = new int[s2.size() + 1];		// not OK
		int count = 0, ptr2 = 0;
		int index2 = -1;
		int i;
		for (i = 0; i <= s2.size(); ++i) {
			if (ptr2 == index2) {
				break;
			}
			if (i == 1) {
				index2 = ptr2;
			}
			for (int ptr1 = 0; ptr1<s1.size(); ++ptr1) {
				if (s1[ptr1] == s2[ptr2]) {
					++ptr2;
				}
				if (ptr2 == s2.size()) {
					++count;
					ptr2 = 0;
				}
			}
			C[i] = count;
		}
		return ((n1 - 1) / (i - 1)*(C[i - 1] - C[0]) + C[(n1 - 1) % (i - 1)]) / n2;
	}
};

#endif // !_LEETCODE_H_
