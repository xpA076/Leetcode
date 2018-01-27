#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string sum;
		int length = (a.size()>b.size()) ? a.size() : b.size();
		char ca, cb;
		for (int i = 0; i<length; i++) {
			ca = (i + a.size() >= length) ? a[i+a.size()-length] : '0';
			cb = (i + b.size() >= length) ? b[i+b.size()-length] : '0';
			if (ca == '0'&&cb == '0') {
				sum += '0';
			}
			else if (ca == '1'&&cb == '1') {
				sum += '2';
			}
			else {
				sum += '1';
			}
		}
		int cache = 0;
		for (int j = length - 1; j >= 0; --j) {
			if (sum[j] == '0') {
				sum[j] = (char)(48+cache);
				cache = 0;
			}
			else if (sum[j] == '2') {
				sum[j] = (char)(48+cache);
				cache = 1;
			}
			else {
				sum[j] = (cache == 0) ? '1' : '0';
			}
		}
		string out;
		if (cache == 1) out += '1';
		return out + sum;
	}
};

#endif // !_LEETCODE_H_
