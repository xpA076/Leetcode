#include"leetcode004.h"

void main()
{
	Solution aa;
	int n1n[5]{ 11,12,13,14,15 };
	vector<int> n1;
	for (int i = 0; i < 5; ++i) { n1.push_back(n1n[i]); }
	int n2n[3]{ 2,3,9 };
	vector<int> n2;
	for (int i = 0; i < 3; ++i) { n2.push_back(n2n[i]); }

	double kk = aa.findMedianSortedArrays(n1, n2);

	system("pause");
}