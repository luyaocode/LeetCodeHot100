#pragma once

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution024
{
public:
	/**
	* 两两交换链表中的节点
	* 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
	* 你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
	*/
	ListNode* swapPairs(ListNode* head);// 双指针 O（N）/O（1）
	void test();
};