#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i<nums.size(); ++i) {
			sum += nums[i];
			flag[i] = true;
		}
		if (sum%k != 0) {
			return false;
		}
		int part = sum / k;
		for (int c = 0; c<k - 1; ++c) {
			if (!findsum(nums, nums.size()-1, part)) return false;
		}
		return true;
	}

private:
	bool flag[16];
	bool findsum(vector<int>& data, int bgn, int sum) {
		for (int i = bgn; i>=0; --i) {
			if (!flag[i]) continue;
			if (data[i]>sum) continue;
			if (data[i] == sum) {
				flag[i] = false;
				return true;
			}
			if (findsum(data, i - 1, sum - data[i])) {
				flag[i] = false;
				return true;
			}
		}
		return false;
	}
};

#endif // !_LEETCODE_H_
