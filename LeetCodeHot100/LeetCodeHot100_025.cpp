#include "LeetCodeHot100_025.h"
#include <iostream>
using std::cout;
using std::endl;

ListNode* Solution025::reverseKGroup(ListNode* head, int k)
{
	/**
	* ��ת������������
	*/
	auto reverse = [](ListNode*& p, ListNode*& prev, ListNode*& prevHead,int k)
	{
		ListNode* newHead = p;
		// �ж��Ƿ���Ҫ��ת
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
		// ��ת����
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
		// ������β
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
	ListNode* prev = NULL;		// ��ǰ�ڵ��ǰ�ڵ�
	ListNode* prevHead = NULL;	// ����ͷ����������β����
	ListNode* newHead = NULL;	// ��ͷ���
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