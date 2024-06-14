#include "LeetCodeHot100_142.h"
#include <iostream>
#include <unordered_set>
using std::cout;
using std::unordered_set;

ListNode* Solution142::detectCycle(ListNode* head)
{
	unordered_set<ListNode*> uset;
	auto p = head;
	while (p != NULL)
	{
		if (uset.find(p) != uset.end())
		{
			return p;
		}
		uset.emplace(p);
		p = p->next;
	}
	return NULL;
}

ListNode* Solution142::detectCycle_A(ListNode* head)
{
	auto fast = head;
	auto slow = head;
	auto p = head;
	while (fast != NULL && slow != NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast != NULL)
		{
			fast = fast->next;
		}
		else
		{
			fast = NULL;
		}
		if (fast == slow)
		{
			break;
		}
	}
	if (fast == NULL)
	{
		return NULL;
	}
	while (1)
	{
		if (p == slow)
		{
			return p;
		}
		p = p->next;
		slow = slow->next;
	}
	return NULL;
}

void Solution142::test()
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
	auto res = detectCycle_A(head);
	cout << res->val;
}