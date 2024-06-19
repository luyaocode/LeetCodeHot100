#include "LeetCodeHot100_021.h"
#include <iostream>
using std::cout;
using std::endl;

ListNode* Solution021::mergeTwoLists(ListNode* list1,ListNode* list2)
{
	auto insert = [](ListNode* list1, ListNode* list2)
	{
		ListNode* p = list1, * q = list2, * prev = NULL;
		ListNode* head{ NULL };
		for (; p != NULL && q != NULL;)
		{
			auto v1 = p->val;
			auto v2 = q->val;
			if (v1 < v2)
			{
				if (head == NULL)
				{
					head = p;
				}
				ListNode* pt= p->next;
				p->next = q;
				if (prev == NULL)
				{
					prev = p;
				}
				else
				{
					prev->next = p;
					prev = p;
				}
				p = pt;
			}
			else
			{
				if (head == NULL)
				{
					head = q;
				}
				prev = q;
				q = q->next;
			}
		}
		if (q == NULL&&prev!=NULL)
		{
			prev->next = p;
		}
		if (head == NULL)
		{
			head = q;
		}
		return head;
	};

	auto l1{ 0 }, l2{ 0 };
	auto p = list1, q = list2;
	while (p != NULL)
	{
		++l1;
		p = p->next;
	}
	while (q != NULL)
	{
		++l2;
		q = q->next;
	}
	if (l1 < l2)
	{
		return insert(list1,list2);
	}
	else
	{
		return insert(list2,list1);
	}
}

void Solution021::test()
{

}