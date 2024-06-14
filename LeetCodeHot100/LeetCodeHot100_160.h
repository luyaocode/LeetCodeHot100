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
    * 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
    */
    ListNode* travel(ListNode* headA, ListNode* headB);
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
    void test();
};
