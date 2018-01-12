#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>


using namespace std;
// 别人有不递归的算法（递归能不用就不用）
class Solution {
public:
	bool isMatch(string s, string p) {
		return isMyFunc(s, 0, p, 0);
	}

private:
	bool isMyFunc(string& s, int ps, string& p, int pp) {
		while (p[pp] != '*') {
			if (p[pp] == '?' || s[ps] == p[pp]) {
				++ps;
				++pp;
				if (ps == s.size() && pp == p.size()) return true;
				if (pp == p.size()) return false;
				if (ps == s.size()) break;
				continue;
			}
			return false;
		}
		while (p[pp] == '*') ++pp;
		if (pp == p.size()) return true;
		for (int i = ps; i<s.size(); ++i) {
			if (s[i] != p[pp]) continue;
			if (isMyFunc(s, i, p, pp)) return true;
		}
		return false;
	}
};

#endif // !_LEETCODE_H_
