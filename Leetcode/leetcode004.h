#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size()<nums2.size()) return myFunc(nums2, nums1);
		else return myFunc(nums1, nums2);
	}

private:
	double myFunc(vector<int>& nl, vector<int>& ns) {
		// abnormal input
		if (ns.size() == 0) {
			if (nl.size() % 2 != 0) return (double)nl[nl.size() / 2];
			else return (double)(nl[nl.size() / 2 - 1] + nl[nl.size() / 2]) / 2.0;
		}
		// main part
		int half = (nl.size() + ns.size()) / 2;		// len(left)<=len(right)
		sprs = ns.size() / 2;
		sprl = half - sprs;
		lsl = 0;
		lsr = ns.size();
		if (ns.size() == 1) {
			if (nl[sprl - 1] > ns[sprs]) {
				++sprs;
				--sprl;
			}
		}
		while(lsr - lsl > 1) {
			if (nl[sprl - 1] > ns[sprs]) {
				// >>sprs
				lsl = sprs;
				sprs = (lsl + lsr + 1) / 2;
				sprl = half - sprs;
				continue;
			}
			if (nl[sprl] < ns[sprs - 1]) {
				// <<sprs
				lsr = sprs;
				sprs = (lsl + lsr) / 2;
				sprl = half - sprs;
				continue;
			}
			break;
		}
		if ((nl.size() + ns.size()) % 2 == 0) return myFuncEven(nl, ns);
		else return myFuncOdd(nl, ns);
	}
	double myFuncOdd(vector<int>& nl, vector<int>& ns) {
		if (sprs == 0) { return (double)min(nl[sprl], ns[sprs]); }
		if (sprs == ns.size()) { return (double)nl[sprl]; }
		return (double)min(nl[sprl], ns[sprs]);
	}
	double myFuncEven(vector<int>& nl, vector<int>& ns) {
		if (nl.size() == ns.size()) {
			if (sprs == 0) { return (double)(nl[sprl - 1] + ns[0]) / 2.0; }
			if (sprs == ns.size()) { return (double)(nl[0] + ns[sprs - 1]) / 2.0; }
			return (double)(max(nl[sprl - 1], ns[sprs - 1]) + min(nl[sprl], ns[sprs])) / 2.0;
		}
		if (sprs == 0) { return (double)(nl[sprl - 1] + min(nl[sprl], ns[0])) / 2.0; }
		if (sprs == ns.size()) { return (double)(max(nl[sprl - 1], ns[sprs - 1]) + nl[sprl]) / 2.0; }
		return (double)(max(nl[sprl - 1], ns[sprs - 1]) + min(nl[sprl], ns[sprs])) / 2.0;
	}
	int sprl, sprs;
	int lsl, lsr;
	int max(int a, int b) { return a > b ? a : b; }
	int min(int a, int b) { return a < b ? a : b; }
};

#endif // !_LEETCODE_H_
