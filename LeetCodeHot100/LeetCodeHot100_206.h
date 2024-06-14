#pragma once

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution206
{
public:
    /**
    * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
    */
    ListNode* reverseList(ListNode* head);
    void test();
};