// LeetCodeHot100.cpp: 定义应用程序的入口点。
//

#include "LeetCodeHot100_148.h"

int main()
{
	Solution148 sol;
	ListNode n1(-1);
	ListNode n2(5);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(0);
	n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;
	sol.sortList(&n1);

	return 0;
}
