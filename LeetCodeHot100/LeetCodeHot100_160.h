#pragma once
#include <cstddef>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution160
{
public:
    /**
    * ���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null ��
    */
    ListNode* travel(ListNode* headA, ListNode* headB);
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
    void test();
};
