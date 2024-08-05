#pragma once
#include <vector>
using std::vector;
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

class Solution108
{
public:
    /**
    * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵平衡二叉搜索树。
    */
    TreeNode* sortedArrayToBST(vector<int>& nums);
    TreeNode* createNode(vector<int>& nums,int left,int right);
};