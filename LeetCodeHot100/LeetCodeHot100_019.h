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
	* ɾ������ĵ����� N �����
	* ����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
	*/
	ListNode* removeNthFromEnd(ListNode* head, int n); // ˫ָ�롣O��N��/O��1��
	void test();
};