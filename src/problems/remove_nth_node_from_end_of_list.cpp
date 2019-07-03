#include "remove_nth_node_from_end_of_list.h"

#include <iostream>

using namespace std;

ListNode* Solution_remove_nth_node_from_end_of_list::removeNthFromEnd(ListNode* head, int n) {
	if (n <= 0) {
		return head;
	}
	int len = 0;
	ListNode *ptr = head;
	while (ptr) {
		ptr = ptr->next;
		len++;
	}
	n = len + 1 - n;
	if (n <= 0 || n > len) {
		return head;
	}

	ListNode *last_ptr = head;
	ptr = head;
	while (ptr) {
		if (n == 1) {
			if (last_ptr == ptr) {
				//no parent, then cut head
				head = head->next;
			}
			else {
				last_ptr->next = ptr->next;
			}
			break;
		}
		else {
			last_ptr = ptr;
			ptr = ptr->next;
			n--;
		}
	}
	return head;
}
void Solution_remove_nth_node_from_end_of_list::test(void) {
	ListNode *head = &ListNode(1);
	ListNode *n1 = &ListNode(2);
	ListNode *n2 = &ListNode(3);
	ListNode *n3 = &ListNode(4);
	ListNode *n4 = &ListNode(5);

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	ListNode *ptr = this->removeNthFromEnd(head, 5);
	while (ptr) {
		cout << ptr->val << ", ";
		ptr = ptr->next;
	}
}