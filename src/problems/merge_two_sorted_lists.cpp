#include "merge_two_sorted_lists.h"

#include <iostream>

using namespace std;

ListNode* Solution_merge_two_sorted_lists::mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *l3 = NULL;
	ListNode *l3_cur = NULL;

	while (l1 || l2) {
		ListNode *cur = NULL;
		if (l1 != 0 && l2 != 0) {
			if (l1->val < l2->val) {
				cur = l1;
				l1 = l1->next;
			}
			else {
				cur = l2;
				l2 = l2->next;
			}
		}
		else if (l1 != 0) {
			cur = l1;
			l1 = l1->next;
		}
		else if (l2 != 0) {
			cur = l2;
			l2 = l2->next;
		}

		cur->next = NULL;
		if (l3 != NULL) {
			l3_cur->next = cur;
			l3_cur = l3_cur->next;
		}
		else {
			l3 = cur;
			l3_cur = l3;
		}
	}

	return l3;
}

void Solution_merge_two_sorted_lists::test(void) {
	ListNode *l1_1 = &ListNode(1);
	ListNode *l1_2 = &ListNode(2);
	ListNode *l1_3 = &ListNode(4);
	l1_1->next = l1_2;
	//l1_2->next = l1_3;

	ListNode *l2_1 = &ListNode(1);
	ListNode *l2_2 = &ListNode(3);
	ListNode *l2_3 = &ListNode(4);
	l2_1->next = l2_2;
	l2_2->next = l2_3;

	ListNode* l = this->mergeTwoLists(l1_1, l2_1);
	while (l) {
		cout << l->val <<", ";
		l = l->next;
	}
}
