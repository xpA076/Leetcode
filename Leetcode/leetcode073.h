#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		// 递归？（不如遍历一遍之后再写零）
		col = matrix[0].size();
		row = matrix.size();
		for (int i = 0; i<row*col; ++i) {
			if (matrix[i / col][i%col] == 0) {
				myFunc(matrix, i);
				break;
			}
		}
	}
	void myFunc(vector<vector<int>>& matrix, int pos) {
		for (int i = pos + 1; i<row*col; ++i) {
			if (matrix[i / col][i%col] == 0) {
				myFunc(matrix, i);
				break;
			}
		}
		for (int j = 0; j<col; ++j) {
			matrix[pos / col][j] = 0;
		}
		for (int k = 0; k<row; ++k) {
			matrix[k][pos%col] = 0;
		}
	}

private:
	int row;
	int col;
};

#endif // !_LEETCODE_H_
