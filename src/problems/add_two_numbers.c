struct ListNode {
    int val;
    struct ListNode *next;
};

#define NULL (0)

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *a, *b, *c, *d;
	struct ListNode *ret = NULL;
	int ten = 0;
	a = l1;
	b = l2;
	c = ret;
	while (1) {
		d = malloc(sizeof(struct ListNode));
		d->next = NULL;
		if (a || b) {
			if (a&&b) {
				d->val = a->val + b->val + ten;
			}
			else if (a) {
				d->val = a->val + 0 + ten;
			}
			else if (b) {
				d->val = 0 + b->val + ten;
			}
			if (d->val >= 10) {
				ten = 1;
				d->val = d->val % 10;
			}else {
				ten = 0;
			}

			if (ret == NULL) {
				ret = d;
				c = ret;
			}else {
				c->next = d;
				c = c->next;
			}
		}else {
			if (ten == 1) {
				d = malloc(sizeof(struct ListNode));
				d->next = NULL;
				d->val = 1;
				c->next = d;
			}
			return ret;
		}

		if (a) {
			a = a->next;
		}
		if (b) {
			b = b->next;
		}
	}
	
	return ret;
}

void test_add_two_numbers(void) {
	//[2, 4, 3]
	//[5, 6, 4]
	struct ListNode l1, l2, l1_2, l1_3, l2_2, l2_3;
	l1.val = 5;
	l1.next = NULL;

	l2.val = 5;
	l2.next = NULL;

	struct ListNode *ret = addTwoNumbers(&l1, &l2);

	struct ListNode *ptr = ret;
	while (ptr != NULL) {
		printf("%d -> ", ptr->val);
		ptr = ptr->next;
	}
}
