#include "merge_k_sorted_lists.h"

#include <iostream>

ListNode* Solution_merge_k_sorted_lists::mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() < 1) {
		return 0;
	}
	int offset = 0;
	ListNode *oneList = 0;
	for (offset = 0; offset < lists.size(); offset++) {
		if (lists[offset] != 0) {
			oneList = lists[offset];
			break;
		}
	}
	for (int i = offset+1; i < lists.size(); i++) {
		ListNode *oneList_last = oneList;
		ListNode *oneList_curr = oneList;
		ListNode *curr_list = lists[i];
		while (curr_list != 0) {
			//find the position for current list item
			while (oneList_curr != 0 && curr_list->val >= oneList_curr->val) {
				oneList_last = oneList_curr;
				oneList_curr = oneList_curr->next;
			}

			ListNode *curr_list_item = curr_list;
			curr_list = curr_list->next;
			if (oneList_curr == oneList) {
				//#1 position is 0
				curr_list_item->next = oneList_curr;
				oneList = curr_list_item;
				oneList_last = curr_list_item;
			}
			else {
				//#2 position is 1...n
				oneList_last->next = curr_list_item;
				curr_list_item->next = oneList_curr;
				oneList_last = curr_list_item;
			}
		}
	}

	return oneList;
}
void Solution_merge_k_sorted_lists::test(void) {
	vector<ListNode*> lists;

	ListNode *a1 = &ListNode(-1);
	ListNode *a2 = &ListNode(-1);
	ListNode *a3 = &ListNode(-1);
	a1->next = a2;
	a2->next = a3;

	ListNode *b1 = &ListNode(-2);
	ListNode *b2 = &ListNode(-2);
	ListNode *b3 = &ListNode(-1);
	b1->next = b2;
	b2->next = b3;
	lists.push_back(a1);
	lists.push_back(b1);

	ListNode* oneList = this->mergeKLists(lists);
	while (oneList != 0) {
		cout << oneList->val << " -> ";
		oneList = oneList->next;
	}
}
