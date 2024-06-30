#include "LeetCodeHot100_025.h"
#include <iostream>
using std::cout;
using std::endl;

ListNode* Solution025::reverseKGroup(ListNode* head, int k)
{
	/**
	* 反转链表匿名函数
	*/
	auto reverse = [](ListNode*& p, ListNode*& prev, ListNode*& prevHead,int k)
	{
		ListNode* newHead = p;
		// 判断是否需要反转
		ListNode* temp = p;
		int count{ 0 };
		while (temp!=NULL&&count<k-1)
		{
			++count;
			temp = temp->next;
		}
		if (temp==NULL)
		{
			if (p != NULL)
			{
				p = p->next;
			}
			return newHead;	
		}
		// 反转链表
		temp = p;
		int i = k;
		while (p != NULL&&i>0)
		{
			auto t = p->next;
			if (i == k)
			{
				p->next = NULL;
			}
			else
			{
				p->next = prev;
			}
			prev = p;
			p =t;
			--i;
		}
		// 连接首尾
		if (prevHead!=NULL)
		{
			prevHead->next = prev;
		}
		if (temp != NULL)
		{
			temp->next = p;
		}
		newHead = prev;
		prev = temp;
		prevHead = temp;
		return newHead;
	};

	auto p = head;
	ListNode* prev = NULL;		// 当前节点的前节点
	ListNode* prevHead = NULL;	// 本组头部（即上组尾部）
	ListNode* newHead = NULL;	// 新头结点
	while (p != NULL)
	{
		auto res=reverse(p,prev,prevHead,k);
		if (newHead == NULL)
		{
			newHead = res;
		}
	}
	return newHead;
}

void Solution025::test()
{
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	auto res=reverseKGroup(&node1,2);
	while (res != NULL)
	{
		cout << res->val << ",";
		res = res->next;
	}
}