#pragma once
#include <cstddef>

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution148
{
public:
    /**
    * ���������ͷ��� head ���뽫�䰴 ���� ���в����� ���������� ��
    * ���ף�������� O(nlogn) ʱ�临�ӶȺͳ������ռ临�Ӷ��£����������������
    */
    ListNode* sortList(ListNode* head); // �����Ե����ϵĹ鲢�����ܴﵽ�������ռ临�Ӷ�
    /**
    * �ϲ�����������������������ͷ���
    */
    ListNode* merge(ListNode* l1,ListNode* l2);
};