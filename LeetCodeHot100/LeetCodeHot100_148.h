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
    * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
    * 进阶：你可以在 O(nlogn) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
    */
    ListNode* sortList(ListNode* head); // 采用自底向上的归并排序，能达到常数级空间复杂度
    /**
    * 合并两个升序链表，返回新链表头结点
    */
    ListNode* merge(ListNode* l1,ListNode* l2);
};