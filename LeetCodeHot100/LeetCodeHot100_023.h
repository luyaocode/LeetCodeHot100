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
    * ����һ���������飬ÿ�������Ѿ����������С�
    * ���㽫��������ϲ���һ�����������У����غϲ��������
    */
    ListNode* mergeKLists(vector<ListNode*>& lists); // ���κϲ�
    ListNode* merge(ListNode* l1,ListNode* l2);
};