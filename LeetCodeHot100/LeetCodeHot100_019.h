#pragma once

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution019
{
public:
	/**
	* 删除链表的倒数第 N 个结点
	* 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
	*/
	ListNode* removeNthFromEnd(ListNode* head, int n); // 双指针。O（N）/O（1）
	void test();
};