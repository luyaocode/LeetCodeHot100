#include "LeetCodeHot100_234.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

bool Solution234::isPalindrome(ListNode* head)
{
	auto p = head;
	vector<int> nums;
	while (p != NULL)
	{
		nums.emplace_back(p->val);
		p = p->next;
	}
	auto size = nums.size();
	for (int i = 0; i < size; ++i)
	{
		if (nums[i] != nums[size -1- i])
		{
			return false;
		}
	}
	return true;
}

void Solution234::test()
{
	ListNode* head{ NULL }, *p{NULL};
	int arr[]{1,2,2,1};
	for (const auto& n : arr)
	{
		if (head == NULL)
		{
			head = new ListNode(n);
			p = head;
		}
		else
		{
			p->next = new ListNode(n);
			p = p->next;
		}
	}

	auto res=isPalindrome(head);
	cout << res;
}