#pragma once
#include <cstddef>

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution141
{
public:
    /**
    * ����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
    * �����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����ע�⣺pos ����Ϊ�������д��� ��������Ϊ�˱�ʶ�����ʵ�������
    * ��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��
    */
    bool hasCycle(ListNode* head);
    void test();
};