#include "LeetCodeHot100_101.h"

bool Solution101::isSymmetric(TreeNode* root)
{
	if (root == nullptr) return true;
	return check(root->left,root->right);
}

bool Solution101::check(TreeNode* p, TreeNode* q)
{
	if (p == nullptr && q == nullptr) return true;	// 如果两者皆空，则两个节点相同
	if (p == nullptr || q == nullptr) return false; // 如果一者为空一者不为空，则两个节点不同
	if (p->val != q->val) return false;				// 如果两者皆不为空，但节点值不相同，则两个节点不同
	return check(p->left, q->right)&&check(p->right,q->left); // 如果节点值相同，则进一步比较p和q的孩子节点是否相同
}
