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

class Solution543
{
private:
    int nNode=0; // �·���ϵĽڵ����
    int depth(TreeNode* node); // �����Ե�ǰ�ڵ�Ϊ���Ķ����������
public:
    /**
    * ����һ�ö������ĸ��ڵ㣬���ظ����� ֱ�� ��
    * �������� ֱ�� ��ָ�������������ڵ�֮���·���� ���� ������·�����ܾ���Ҳ���ܲ��������ڵ� root ��
    * ���ڵ�֮��·���� ���� ������֮�������ʾ��
    */
    int diameterOfBinaryTree(TreeNode* root);
};