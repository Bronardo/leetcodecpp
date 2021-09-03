#include "AddTwoNumbers.h"

ListNode* AddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* ans=nullptr;
	ListNode* p = nullptr;
	int carry = 0;
	while (l1 || l2 || carry) {
		if (l1) {
			carry += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			carry += l2->val;
			l2 = l2->next;
		}
		ListNode* t = new ListNode(carry % 10);
		if (ans) {
			p->next = t;
			p = p->next;
		}
		else {
			ans = t;
			p = t;
		}
		carry /= 10;
	}
	return ans;
}
