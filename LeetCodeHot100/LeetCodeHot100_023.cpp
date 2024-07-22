#include "LeetCodeHot100_023.h"

ListNode* Solution023::mergeKLists(vector<ListNode*>& lists)
{
	int size = lists.size();
	if (size == 0)
	{
		return nullptr;
	}
	for (int subLen = 1; subLen < size; subLen<<=1)
	{
		int currIdx = 0;
		while (currIdx < size)
		{
			ListNode* second = nullptr;
			if (currIdx + subLen < size) // 下一个子链表头结点要么落在初始链表上，要么在初始链表外，如果在初始链表外，置为nullptr。
			{
				second = lists[currIdx + subLen];
			}
			auto merged=merge(lists[currIdx], second);
			lists[currIdx] = merged;
			currIdx += 2*subLen;
		}
	}
	return lists[0];
}

ListNode* Solution023::merge(ListNode* l1, ListNode* l2)
{
	auto hair = new ListNode(0);
	auto p = l1;
	auto q = l2;
	auto t = hair;
	while (p != nullptr && q != nullptr)
	{
		if (p->val <= q->val)
		{
			t->next = p;
			p = p->next;
		}
		else
		{
			t->next = q;
			q = q->next;
		}
		t = t->next;
	}
	if (p != nullptr)
	{
		t->next = p;
	}
	else if (q != nullptr)
	{
		t->next = q;
	}
	auto res = hair->next;
	delete hair;
	hair = nullptr;
	return res;
}
