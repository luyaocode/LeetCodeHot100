// LeetCodeHot100.cpp: 定义应用程序的入口点。
//

#include "LeetCodeHot100_023.h"
#include <vector>
using std::vector;

int main()
{
	Solution023 sol;
	vector<ListNode*> lists;
	ListNode n11(1);
	lists.push_back(&n11);

	ListNode n21(0);
	ListNode n22(3);
	ListNode n23(4);
	n21.next = &n22;
	lists.push_back(&n21);

	ListNode n31(2);
	ListNode n32(6);
	n31.next = &n32;
	lists.push_back(&n31);

	sol.mergeKLists(lists);
	return 0;
}
