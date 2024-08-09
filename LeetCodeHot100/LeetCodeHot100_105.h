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
    * ���������������� preorder �� inorder ������ preorder �Ƕ���������������� inorder ��ͬһ����������������빹�����������������ڵ㡣   
    * preorder �� inorder �� ���ظ� Ԫ��
    */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
    TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight, int inLeft, int inRight);
};