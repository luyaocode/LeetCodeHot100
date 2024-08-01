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

class Solution226
{
public:
    /**
    * ����һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣
    */
    TreeNode* invertTree(TreeNode* root);
};