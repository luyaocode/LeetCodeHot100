#include "LeetCodeHot100_206.h"
#include <iostream>
using std::cout;
using std::endl;

ListNode* Solution206::reverseList(ListNode* head)
{
	auto p = head;
	ListNode* prev{ NULL };
	while (p!=NULL)
	{
		auto temp = p->next;
		p->next = prev;
		prev = p;
		p = temp;
	}
	return prev;
}

void Solution206::test()
{
	int n1[]{ 1,9,1,2,4 };
	ListNode* head{ NULL }, * p{NULL};
	for (const auto& n : n1)
	{
		if (head == NULL)
		{
			head = new ListNode(n);
			p = head;
		}
		else
		{
			p->next = new ListNode(n);
			p = p->next;
		}
	}
	p = head;
	cout << "初始链表" << endl;
	while (p != NULL)
	{
		cout << p->val << ",";
		p = p->next;
	}
	cout << endl;
	auto res=reverseList(head);
	p = res;
	cout << "反转链表" << endl;
	while (p != NULL)
	{
		cout << p->val << ",";
		p = p->next;
	}
}
