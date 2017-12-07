#pragma once
#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include<iostream>
#include<vector>


using namespace std;
// list node
struct RangeNode {
	int Left;
	int Right;
	RangeNode* Next;
	RangeNode(int left, int right) : Left(left), Right(right), Next(NULL) {}
};

class RangeModule {
public:
	RangeModule() {
		root = new RangeNode(0, 0);
	}

	void addRange(int left, int right) {
		if (left >= right) {
			return;
		}
		RangeNode* ptr1 = root->Next;
		RangeNode* ptr2 = root;
		while (ptr1 != NULL) {
			if (left > ptr1->Right) {
				ptr2 = ptr1;
				ptr1 = ptr1->Next;
				continue;
			}
			// make ptr1 to the new range
			if (left < ptr1->Left) {
				ptr2->Next = new RangeNode(left, right);
				ptr2->Next->Next = ptr1;
				ptr1 = ptr2->Next;
			}
			else {
				if (ptr1->Right < right) {
					ptr1->Right = right;
				}
			}
			ptr2 = ptr1;
			ptr1 = ptr1->Next;
			while (ptr1!=NULL) {
				if (right < ptr1->Left) {
					return;
				}
				if (right >= ptr1->Left&&right < ptr1->Right) {
					ptr2->Right = ptr1->Right;
					ptr2->Next = ptr1->Next;
					delete ptr1;
					ptr1 = ptr2->Next;
					return;
				}
				ptr2->Next = ptr1->Next;
				delete ptr1;
				ptr1 = ptr2->Next;
			}
			return;
		}
		ptr2->Next = new RangeNode(left, right);
	}

	bool queryRange(int left, int right) {
		if (left >= right) {
			return false;
		}
		RangeNode* ptr = root->Next;
		while (true) {
			if (ptr == NULL) {
				return false;
			}
			if (left < ptr->Left) {
				return false;
			}
			if (left > ptr->Right) {
				ptr = ptr->Next;
				continue;
			}
			if (right > ptr->Left&&right <= ptr->Right) {
				return true;
			}
			else {
				return false;
			}
		}
	}

	void removeRange(int left, int right) {
		if (left >= right) {
			return;
		}
		RangeNode* ptr1 = root->Next;
		RangeNode* ptr2 = root;
		while (ptr1 != NULL) {
			if (left > ptr1->Right) {
				ptr2 = ptr1;
				ptr1 = ptr1->Next;
				continue;
			}
			// make ptr1 to the 1st to delete
			if (left > ptr1->Left) {
				ptr2 = ptr1;
				ptr1 = ptr1->Next;
				if (right < ptr2->Right) {
					ptr2->Next = new RangeNode(right, ptr2->Right);
					ptr2->Right = left;
					ptr2->Next->Next = ptr1;
					return;
				}
				ptr2->Right = left;
			}
			while (ptr1 != NULL) {
				if (right <= ptr1->Left) {
					return;
				}
				if (right > ptr1->Left&&right < ptr1->Right) {
					ptr1->Left = right;
					return;
				}
				ptr2->Next = ptr1->Next;
				delete ptr1;
				ptr1 = ptr2->Next;
			}
			return;
		}
	}

private:
	RangeNode* root;

};





/**
* Your RangeModule object will be instantiated and called as such:
* RangeModule obj = new RangeModule();
* obj.addRange(left,right);
* bool param_2 = obj.queryRange(left,right);
* obj.removeRange(left,right);
*/

#endif // !_LEETCODE_H_
