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
    * ����һ���������ͷ�ڵ� head �������жϸ������Ƿ�Ϊ������������ǣ����� true �����򣬷��� false ��
    * �����нڵ���Ŀ�ڷ�Χ[1, 10^5] �ڣ�0 <= Node.val <= 9
    */
    bool isPalindrome(ListNode* head);
    void test();
};
