#pragma once

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution025
{
public:
	/**
	* 25. K ��һ�鷭ת����
	* ���������ͷ�ڵ� head ��ÿ k ���ڵ�һ����з�ת�����㷵���޸ĺ������
	* k ��һ��������������ֵС�ڻ��������ĳ��ȡ�����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��
	* �㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʽ��нڵ㽻����
	*/
	ListNode* reverseKGroup(ListNode* head, int k);
	void test();
};