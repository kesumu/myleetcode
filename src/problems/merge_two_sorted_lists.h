#pragma once
#define NULL 0


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_merge_two_sorted_lists {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
	void test(void);
};