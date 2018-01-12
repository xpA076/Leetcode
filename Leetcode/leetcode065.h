#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>

using namespace std;

// ¿±º¶Ã‚÷–µƒ¿±º¶£°

class Solution {
public:
	bool isNumber(string s) {
		int i = 0;
		int pos[2]{ -1,-1 };
		int session = 0;
		bool isnum = true;
		for (; i<s.length(); ++i) {
			// remove space
			if (s[i] == ' ') {
				continue;
			}
			if (session == 0) {
				session++;
				pos[0] = i;
			}
			// find char e
			if (s[i] != 'e') {
				continue;
			}
			else {
				pos[1] = i;
				break;
			}
		}
		if (pos[0] == -1) {
			return false;
		}
		if (pos[1] == -1) {
			isnum = myIsNum(s, pos[0], s.length() - 1);
		}
		else {
			isnum &= myIsNum(s, pos[0], pos[1] - 1);
			if (s[pos[1] - 1] == ' ') {
				return false;
			}
			isnum &= myIsInteger(s, pos[1] + 1, s.length() - 1);
		}
		return isnum;

	}

private:
	bool myIsNum(string&s, int sBegin, int sEnd) {
		int begin = sBegin;
		int i;
		int dotPos = -1;
		bool hasnum = false;
		int session = 0;
		if (s[begin] == '+' || s[begin] == '-') {
			begin++;
			session = 1;
		}
		for (i = begin; i <= sEnd; i++) {
			if (s[i] == ' ') {
				if (session == 1) {
					session++;
				}
				continue;
			}
			else {
				if (session == 0) {
					session++;
				}
				if (session == 2) {
					return false;
				}
			}
			if (s[i] >= '0'&&s[i] <= '9') {
				hasnum = true;
				continue;
			}
			else if (s[i] == '.') {
				if (dotPos == -1) {
					dotPos = i;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		if (!hasnum) {
			return false;
		}
		return true;
	}
	bool myIsInteger(string&s, int sBegin, int sEnd) {
		int begin = sBegin;
		int i;
		bool hasnum = false;
		int session = 1;
		if (s[begin] == '+' || s[begin] == '-') {
			begin++;
			session = 1;
		}
		for (i = begin; i <= sEnd; i++) {
			if (s[i] == ' ') {
				if (session == 1) {
					session++;
				}
				continue;
			}
			else {
				if (session == 0) {
					session++;
				}
				if (session == 2) {
					return false;
				}
			}
			if (s[i] >= '0'&&s[i] <= '9') {
				hasnum = true;
				continue;
			}
			else {
				return false;
			}
		}
		if (!hasnum) {
			return false;
		}
		return true;
	}
};

#endif // !_LEETCODE_H_
