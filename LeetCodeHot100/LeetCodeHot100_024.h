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
	* �������������еĽڵ�
	* ����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣
	* ������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������
	*/
	ListNode* swapPairs(ListNode* head);// ˫ָ�� O��N��/O��1��
	void test();
};