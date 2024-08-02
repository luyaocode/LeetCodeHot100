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

class Solution101
{
public:
    /**
    * ����һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�
    */
    bool isSymmetric(TreeNode* root);
    bool check(TreeNode* p,TreeNode* q);
};