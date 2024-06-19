#include "LeetCodeHot100_002.h"
#include <iostream>
using std::cout;
using std::endl;

ListNode* Solution002::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	//auto reverse = [](ListNode* head)
	//{
	//	auto p = head;
	//	ListNode* prev = NULL;
	//	while (p!= NULL)
	//	{
	//		auto next = p->next;
	//		p->next = prev;
	//		prev = p;
	//		p = next;
	//	}
	//	return prev;
	//};
	//auto p=reverse(l1);
	//auto q=reverse(l2);
	auto p = l1;
	auto q = l2;
	int flag = 0;
	ListNode* newNode = NULL;
	ListNode* prev = NULL;
	ListNode* head = NULL;
	while (p != NULL && q != NULL)
	{
		auto val = (p->val + q->val+flag) % 10;
		flag = (p->val + q->val+ flag) / 10 >= 1 ? 1 : 0;
		newNode = new ListNode(val);
		if (head == NULL)
		{
			head = newNode;
		}
		if (prev != NULL)
		{
			prev->next = newNode;
		}
		prev = newNode;
		p = p->next;
		q = q->next;
	}
	if (p == NULL)
	{
		while (q != NULL)
		{
			auto val = (q->val+flag) % 10;
			flag = (q->val+flag) / 10 >= 1 ? 1 : 0;
			newNode = new ListNode(val);
			if (head == NULL)
			{
				head = newNode;
			}
			if (prev != NULL)
			{
				prev->next = newNode;
			}
			prev = newNode;
			q = q->next;
		}
	}
	else if (q == NULL)
	{
		while (p != NULL)
		{
			auto val = (p->val + flag) % 10;
			flag = (p->val + flag) / 10 >= 1 ? 1 : 0;
			newNode = new ListNode(val);
			if (head == NULL)
			{
				head = newNode;
			}
			if (prev != NULL)
			{
				prev->next = newNode;
			}
			prev = newNode;
			p = p->next;
		}
	}
	if (flag == 1)
	{
		newNode = new ListNode(1);
		if (prev != NULL)
		{
			prev->next = newNode;
		}
	}
	//return reverse(head);
	return head;
}

void Solution002::test()
{
	ListNode node1(3);
	ListNode node2(2);
	ListNode node3(4);
	node1.next = &node2;
	node2.next = &node3;
	ListNode node4(1);
	ListNode node5(2);
	ListNode node6(5);
	node4.next = &node5;
	node5.next = &node6;
	auto res=addTwoNumbers(&node1,&node4);
}