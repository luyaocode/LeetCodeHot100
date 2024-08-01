#pragma once
#include <vector>
using std::vector;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution094
{
private:
    vector<int> _inorder = vector<int>();
public:
    /**
    * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
    */
    vector<int> inorderTraversal(TreeNode* root);
    void inorder(TreeNode* node);

};