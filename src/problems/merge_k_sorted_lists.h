#pragma once
#include <vector>

#define NULL 0

using namespace std;
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution_merge_k_sorted_lists {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists);
	void test(void);
};