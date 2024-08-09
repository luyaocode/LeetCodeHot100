#pragma once
// Definition for a binary tree node.
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution105
{
private:
    unordered_map<int, int> index;
public:
    /**
    * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。   
    * preorder 和 inorder 均 无重复 元素
    */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
    TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight, int inLeft, int inRight);
};