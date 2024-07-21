#include "LeetCodeHot100_148.h"
#include <iostream>
using std::cout;
using std::endl;

ListNode* Solution148::sortList(ListNode* head)
{
	// ����������
	auto p = head;
	auto size{ 0 };
	while (p != nullptr)
	{
		++size;
		p = p->next;
	}
	if (size <= 1)
	{
		return head;
	}
	// �鲢����
	auto hair = new ListNode(0,head); // �����ƽڵ�򻯲���	
	for (int subLen = 1;  subLen< size; subLen <<= 1)
	{
		auto curr = hair->next; // ��ǰ�ڵ�
		auto prev = hair;		// ������β��
		while (curr!=nullptr)
		{
			auto head1 = curr;			//��һ��������ͷ���
			for (int i = 1; i < subLen && curr->next != nullptr; ++i) // ע������i��1��ʼ����Ϊcurr����Ҳ������subLen֮��
			{
				curr = curr->next;
			}
			auto head2 = curr->next;	// �ڶ���������ͷ���
			curr->next = nullptr;		// ��һ�����������
			curr = head2;
			for (int i = 1; i < subLen && curr!= nullptr&&curr->next != nullptr; ++i)
			{
				curr = curr->next;
			}
			ListNode* next = nullptr;
			if (curr != nullptr)
			{
				next = curr->next;		// ��һ��whileѭ������ʼ�ڵ�
				curr->next = nullptr;	// �ڶ������������
			}
			auto merged = merge(head1,head2);
			// ��������ҵ�������β��
			prev->next = merged;
			// ���¾�����βָ��Ϊ������β��
			while (prev->next != nullptr)
			{
				prev = prev->next;
			}
			// ���µ�ǰ�ڵ�
			curr = next;
		}
	}
	return hair->next;
}

ListNode* Solution148::merge(ListNode* l1, ListNode* l2)
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
	return hair->next;
}
