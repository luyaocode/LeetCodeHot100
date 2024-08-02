#include "LeetCodeHot100_101.h"

bool Solution101::isSymmetric(TreeNode* root)
{
	if (root == nullptr) return true;
	return check(root->left,root->right);
}

bool Solution101::check(TreeNode* p, TreeNode* q)
{
	if (p == nullptr && q == nullptr) return true;	// ������߽Կգ��������ڵ���ͬ
	if (p == nullptr || q == nullptr) return false; // ���һ��Ϊ��һ�߲�Ϊ�գ��������ڵ㲻ͬ
	if (p->val != q->val) return false;				// ������߽Բ�Ϊ�գ����ڵ�ֵ����ͬ���������ڵ㲻ͬ
	return check(p->left, q->right)&&check(p->right,q->left); // ����ڵ�ֵ��ͬ�����һ���Ƚ�p��q�ĺ��ӽڵ��Ƿ���ͬ
}
