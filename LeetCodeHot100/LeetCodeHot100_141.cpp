#include "LeetCodeHot100_141.h"
#include <iostream>
using std::cout;

bool Solution141::hasCycle(ListNode* head)
{
	auto p = head;
	auto q = head;
	while (q != NULL&&p!=NULL&&p->next!=NULL)
	{
		p = p->next->next;
		q = q->next;
		if (p == q)
		{
			return true;
		}
	}
	return false;
}

void Solution141::test()
{
	int n1[]{ 1,9,1,2,4 };
	int pos{2};
	int count{0};
	ListNode* head{ NULL }, * p{ NULL }, * q{ NULL }, * rear{NULL};
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
			if (count == 2)
			{
				q = p;
			}
			p = p->next;
			rear = p;
		}
		++count;
	}
	rear->next = q;
	auto res = hasCycle(head);
	cout << res;
}