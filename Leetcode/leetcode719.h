#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
	int smallestDistancePair(vector<int>& nums, int k) {
		vector<int> dsts;
		for (int i = 0; i<nums.size(); i++) {
			for (int j = i + 1; j<nums.size(); i++) {
				dsts.push_back(dst(nums[i], nums[j]));
			}
		}
		if (dsts.size() == 1) {
			return dsts.at(0);
		}
		return Qslct(dsts, k, 0, dsts.size() - 1);
	}

private:
	int cutoff = 10;
	int Sslct(vector<int>& nums, int k, int left, int right) {
		for (int i = left; i<right; i++) {
			for (int j = i + 1; j<right; j++) {
				if (nums[i]>nums[j]) {
					swap(nums[i], nums[j]);
				}
			}
		}
		return nums[left + k - 1];
	}
	int Qslct(vector<int>& nums, int k, int left, int right) {
		int pivot;
		int i, j;
		if (right - left>cutoff) {
			pivot = m3(nums, left, right);
			i = left;
			j = right - 1;
			while (true) {
				while (nums[++i]<pivot) {}
				while (nums[--j]>pivot) {}
				if (i<j) {
					swap(nums[i], nums[j]);
				}
				else {
					break;
				}
			}
			swap(nums[i], nums[right - 1]);
			if (k <= i) return Qslct(nums, k, left, i - 1);
			if (k = i + 1) return nums[i];
			if (k>i + 1) return Qslct(nums, k, i + 1, right);
		}
		else {
			return Sslct(nums, k, left, right);
		}
	}
	int dst(int a, int b) {
		return (a>b) ? (a - b) : (b - a);
	}
	void swap(int& a, int& b) {
		int k = a;
		a = b;
		b = k;
	}
	int m3(vector<int>& nums, int left, int right) {
		if (nums[left]>nums[(left + right) / 2]) swap(nums[left], nums[(left + right) / 2]);
		if (nums[left]>nums[right]) swap(nums[left], nums[right]);
		if (nums[(left + right) / 2]>nums[right]) swap(nums[(left + right) / 2], nums[right]);
		swap(nums[(left + right) / 2], nums[right - 1]);
		return nums[right - 1];
	}
};

#endif // !_LEETCODE_H_
