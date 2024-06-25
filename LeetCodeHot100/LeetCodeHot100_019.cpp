#include "LeetCodeHot100_019.h"
#include <iostream>
using std::cout;
using std::endl;

ListNode* Solution019::removeNthFromEnd(ListNode* head, int n)
{
	if (head == NULL||n<=0)
	{
		return NULL;
	}
	auto front = head;
	int i{ 0 };
	for(;i<n&&front!=NULL;++i)
	{
		front = front->next;
	}
	if (i < n)
	{
		return NULL;
	}
	auto back = head;
	ListNode* prev = NULL;
	while (front != NULL)
	{
		front = front->next;
		if (prev == NULL)
		{
			prev = head;
		}
		else
		{
			prev = back;
		}
		back = back->next;
	}

	if (prev == NULL) // Delete head
	{
		auto t = head->next;
		head->next = NULL;
		delete head;
		return t;
	}
	else // Delete node
	{
		prev->next = back->next;
		back->next = NULL;
		delete back;
		return head;
	}
}

void Solution019::test()
{

}