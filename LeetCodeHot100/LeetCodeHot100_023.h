#pragma once
#include <vector>
using std::vector;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution023
{
public:
    /**
    * 给你一个链表数组，每个链表都已经按升序排列。
    * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
    */
    ListNode* mergeKLists(vector<ListNode*>& lists); // 分治合并
    ListNode* merge(ListNode* l1,ListNode* l2);
};