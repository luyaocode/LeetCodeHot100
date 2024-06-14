#pragma once

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution234
{
public:
    /**
    * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
    * 链表中节点数目在范围[1, 10^5] 内，0 <= Node.val <= 9
    */
    bool isPalindrome(ListNode* head);
    void test();
};
