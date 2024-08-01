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
    * 给定一个二叉树 root ，返回其最大深度。
    * 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
    */
    int maxDepth(TreeNode* root);
    void inorder(TreeNode* node,int& level);
};