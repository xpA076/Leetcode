#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (nums.size() == 1) { return 0; }
		sort(nums.begin(), nums.end());
		int idx = 0;
		int count = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			if (nums.at(i) > *nums.end() - k) {	break; }
			if (i != 0 && nums.at(i) == nums.at(i - 1)) { continue;	}
			4
		}
	}
};


#endif // !_LEETCODE_H_
