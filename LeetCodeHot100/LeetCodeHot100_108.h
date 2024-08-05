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
    * ����һ���������� nums ������Ԫ���Ѿ��� ���� ���У����㽫��ת��Ϊһ��ƽ�������������
    */
    TreeNode* sortedArrayToBST(vector<int>& nums);
    TreeNode* createNode(vector<int>& nums,int left,int right);
};