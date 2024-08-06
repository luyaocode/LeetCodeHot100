#pragma once
// Definition for a binary tree node.
#include <vector>
using std::vector;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution230
{
private:
    vector<int> _inorder;
public:
    int kthSmallest(TreeNode* root, int k);
    void inorder(TreeNode* node);
};