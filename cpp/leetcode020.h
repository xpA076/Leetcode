#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
	bool isValid(string s) {
		vector<char> stk;
		for (int i = 0; i<s.size(); ++i) {
			switch (s[i]){
			case '(':
				stk.push_back(s[i]);
				break;
			case '[':
				stk.push_back(s[i]);
				break;
			case '{':
				stk.push_back(s[i]);
				break;
			case ')':
				if (stk.empty() || stk[stk.size() - 1] != '(') {
					return false;
				}
				else {
					stk.pop_back();
					break;
				}
			case ']':
				if (stk.empty() || stk[stk.size() - 1] != '[') {
					return false;
				}
				else {
					stk.pop_back();
					break;
				}
			case '}':
				if (stk.empty() || stk[stk.size() - 1] != '{') {
					return false;
				}
				else {
					stk.pop_back();
					break;
				}
			default:
				return false;
			}
		}
		return stk.empty();
	}
};

#endif // !_LEETCODE_H_
