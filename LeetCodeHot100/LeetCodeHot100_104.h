#pragma once
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution104
{
private:
    int _maxDepth=0;
public:
    /**
    * ����һ�������� root �������������ȡ�
    * �������� ������ ��ָ�Ӹ��ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
    */
    int maxDepth(TreeNode* root);
    void inorder(TreeNode* node,int& level);
};