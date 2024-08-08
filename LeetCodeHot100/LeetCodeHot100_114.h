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

class Solution114
{
public:
    /**
    * ����������ĸ���� root �����㽫��չ��Ϊһ��������
    * չ����ĵ�����Ӧ��ͬ��ʹ�� TreeNode ������ right ��ָ��ָ����������һ����㣬������ָ��ʼ��Ϊ null ��
    * չ����ĵ�����Ӧ��������� ������� ˳����ͬ��
    */
    void flatten(TreeNode* root);
    void preorder(TreeNode* node, vector<TreeNode*>& nodes);
};