#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
	int integerReplacement(int n) {
		int count = 0;
		int binLen = 0;
		int flag = 1;
		int nn = n;
		int ptr = 0;
		int isCounting;
		int countOne = 0;
		int countZro = 0;
		// highest 1 position
		while (nn != 1) {
			binLen++;
			nn /= 2;
		}
		for (; ptr <= binLen; ptr++) {
			if ((n&flag) != 0) {
				isCounting = 1;
				break;
			}
			flag = flag << 1;
		}
		// start main part
		for (; ptr <= binLen; ptr++) {
			if ((n&flag) == 0) {
				isCounting = 0;
				countZro++;
				flag = flag << 1;
				continue;
			}
			else {
				if (isCounting == 1) {
					countOne++;
					flag = flag << 1;
					continue;
				}
			}
			// analyze TO DO
			if (countOne == 1) {
				count += 1;
			}
			else {
				if (countZro == 1) {
					countOne = 2;
					count += 1;
				}
				else {
					countOne = 1;
					count += 2;
				}
			}
			countZro = 0;
			isCounting = 1;
			flag = flag << 1;
		}
		if (countOne == 2) {
			count += 1;
		}
		if (countOne >= 3) {
			count += 2;
		}
		count += binLen;
		return count;



	}
};

#endif // !_LEETCODE_H_
