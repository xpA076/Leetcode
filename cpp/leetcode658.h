#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		static vector<int> ret;
		ret.clear();
		ret.resize(k);
		int idx = (arr.size() - k) / 2;
		for (int low = 0, high = arr.size() - k;; idx = (low + high) / 2) {
			if (idx > 0 && abs(x - arr.at(idx - 1) <= abs(x - arr.at(idx + k - 1)))) {
				high = idx;
				--idx;
			}
			else if (idx + k - 1 < arr.size() - 1 && abs(x - arr.at(idx + k)) < abs(x - arr.at(idx))) {
				low = idx;
				++idx;
			}
			else {
				break;
			}
			if (high <= low + 1) { break; }
		}
		copy(arr.begin() + idx, arr.begin() + (idx + k), ret.begin());
		return ret;
	}
};

#endif // !_LEETCODE_H_
