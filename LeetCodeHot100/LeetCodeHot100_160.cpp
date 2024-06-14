#include "LeetCodeHot100_160.h"
#include <iostream>
#include <unordered_set>
using std::cout;
using std::endl;
using std::unordered_set;

ListNode* Solution160::travel(ListNode* headA, ListNode* headB)
{
	unordered_set<ListNode*> ps;
	auto p = headA;
	auto q = headB;
	while (p!= NULL)
	{
		ps.insert(p);
		p = p->next;
	}
	while (q != NULL)
	{
		if (ps.find(q) != ps.end())
		{
			return q;
		}
		q = q->next;
	}
	return NULL;
}

ListNode* Solution160::getIntersectionNode(ListNode* headA, ListNode* headB)
{
	auto r1=travel(headA, headB);
	if (r1 != NULL)
		return r1;
	auto r2 = travel(headB, headA);
	if (r2 != NULL)
		return r2;
	return NULL;
}

void Solution160::test()
{
	int n1[]{ 1,9,1,2,4 };
	int n2[]{3,2,4};
	int idx{0};
	ListNode* headA{ NULL }, * headB{ NULL }, * p{ NULL }, * banana{NULL};
	for (const auto& n : n1)
	{
		if (headA == NULL)
		{
			headA = new ListNode(n);
			p = headA;
		}
		else
		{
			p->next = new ListNode(n);
			p = p->next;
			if (idx == 3)
			{
				banana = p;
			}
		}
		++idx;
	}
	idx = 0;
	for (const auto& n : n2)
	{
		if (headB == NULL)
		{
			headB = new ListNode(n);
			p = headB;
		}
		else
		{
			if (idx == 1)
			{
				p->next = banana;
			}
		}
		++idx;
	}
	p = headA;
	cout << "链表A" << endl;
	while (p != NULL)
	{
		cout << p->val << ",";
		p = p->next;
	}
	cout << endl;
	p = headB;
	cout << "链表B" << endl;
	while (p != NULL)
	{
		cout << p->val << ",";
		p = p->next;
	}
	cout << endl;
	auto pres = getIntersectionNode(headA,headB);
	cout << "相交点：" << (pres->val) << endl;
}