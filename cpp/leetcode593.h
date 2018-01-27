#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		if (vldRct(p1, p2, p3) && vldRct(p2, p3, p4) && vldRct(p3, p4, p1)) return true;
		if (vldRct(p1, p3, p2) && vldRct(p3, p2, p4) && vldRct(p2, p4, p1)) return true;
		if (vldRct(p3, p1, p2) && vldRct(p1, p2, p4) && vldRct(p2, p4, p3)) return true;
		return false;
	}
	bool vldRct(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
		int x1 = p2.at(0) - p1.at(0);
		int x2 = p3.at(0) - p2.at(0);
		int y1 = p2.at(1) - p1.at(1);
		int y2 = p3.at(1) - p2.at(1);
		if (x1*x2 + y1*y2 != 0) {
			return false;
		}
		if ((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0)) {
			return false;
		}
		if ((x1 + y2 == 0 && x2 == y1) || (x2 + y1 == 0 && x1 == y2)) {
			return true;
		}
		return false;
	}
};
#endif // !_LEETCODE_H_
