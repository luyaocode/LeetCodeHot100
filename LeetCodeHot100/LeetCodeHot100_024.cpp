#include "LeetCodeHot100_024.h"
#include <iostream>
using std::cout;
using std::endl;

ListNode* Solution024::swapPairs(ListNode* head)
{
	auto p = head;
	ListNode* prevP = NULL; // pǰָ��
	ListNode* nextP = NULL; // p������ָ��
	ListNode* newHead = head;

	while (p!=NULL&&p->next != NULL)
	{
		nextP = p->next->next;
		if (newHead == head)
		{
			newHead = p->next;
		}
		// swap
		auto q = p->next;
		if (prevP != NULL)
		{
			prevP->next = q;
		}
		prevP = p;
		q->next = p;
		p->next = nextP;
		// move
		p = nextP;
	}
	return newHead;
}

void Solution024::test()
{

}