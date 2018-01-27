#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int compress(vector<char>& chars) {
		int count = 1;
		int length = 0;
		int i;
		for (i = 1; i<chars.size(); i++) {
			if (chars.at(i) != chars.at(i - 1)) {
				chars.at(length) = chars.at(i - 1);
				length += 1;
				if (count >= 100) {
					chars.at(length) = (char)(count / 100 + 48);
					length++;
				}
				if (count >= 10) {
					chars.at(length) = (char)((count / 10) % 10 + 48);
					length++;
				}
				if (count != 1) {
					chars.at(length) = (char)(count % 10 + 48);
					length++;
				}
				count = 1;
			}
			else {
				count++;
			}
		}
		chars.at(length) = chars.at(i - 1);
		length += 1;
		if (count >= 100) {
			chars.at(length) = (char)(count / 100 + 48);
			length++;
		}
		if (count >= 10) {
			chars.at(length) = (char)((count / 10) % 10 + 48);
			length++;
		}
		if (count != 1) {
			chars.at(length) = (char)(count % 10 + 48);
			length++;
		}
		count = 1;
		return length;
	}
};





#endif // !_LEETCODE_H_



