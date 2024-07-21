#include "LeetCodeHot100_148.h"
#include <iostream>
using std::cout;
using std::endl;

ListNode* Solution148::sortList(ListNode* head)
{
	// 计算链表长度
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
	// 归并排序
	auto hair = new ListNode(0,head); // 定义哑节点简化操作	
	for (int subLen = 1;  subLen< size; subLen <<= 1)
	{
		auto curr = hair->next; // 当前节点
		auto prev = hair;		// 旧链表尾部
		while (curr!=nullptr)
		{
			auto head1 = curr;			//第一个子链表头结点
			for (int i = 1; i < subLen && curr->next != nullptr; ++i) // 注意这里i从1开始，因为curr本身也计算在subLen之内
			{
				curr = curr->next;
			}
			auto head2 = curr->next;	// 第二个子链表头结点
			curr->next = nullptr;		// 第一个子链表断链
			curr = head2;
			for (int i = 1; i < subLen && curr!= nullptr&&curr->next != nullptr; ++i)
			{
				curr = curr->next;
			}
			ListNode* next = nullptr;
			if (curr != nullptr)
			{
				next = curr->next;		// 下一次while循环的起始节点
				curr->next = nullptr;	// 第二个子链表断链
			}
			auto merged = merge(head1,head2);
			// 将新链表挂到旧链表尾部
			prev->next = merged;
			// 更新旧链表尾指针为新链表尾部
			while (prev->next != nullptr)
			{
				prev = prev->next;
			}
			// 更新当前节点
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
