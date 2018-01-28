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
		if (nums.size() <= 1) { return 0; }
		sort(nums.begin(), nums.end());
		int idx = 1;
		int count = 0;
		int lastcount = nums.at(0);
		int endnum = nums.at(nums.size() - 1);
		for (int i = 0; i < nums.size() - 1; ++i) {
			if (nums.at(i) > endnum - k) {	break; }
			if (i != 0 && nums.at(i) == lastcount) { continue;	}
			if (idx <= i) { idx = i + 1; }
			while (nums.at(idx) < nums.at(i) + k) { ++idx; }
			if (nums.at(idx) == nums.at(i) + k) { 
				++count; 
				lastcount = nums.at(i); 
			}
		}
		return count;
	}
};


#endif // !_LEETCODE_H_
