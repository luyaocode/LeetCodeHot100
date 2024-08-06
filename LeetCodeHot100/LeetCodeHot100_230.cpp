#include "LeetCodeHot100_230.h"

int Solution230::kthSmallest(TreeNode* root, int k)
{
	inorder(root);
	return _inorder[k-1];
}

void Solution230::inorder(TreeNode* node)
{
	if (!node) return;
	inorder(node->left);
	_inorder.push_back(node->val);
	inorder(node->right);
}
