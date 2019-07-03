#pragma once

#define NULL 0

 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution_remove_nth_node_from_end_of_list {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n);
	void test(void);
};