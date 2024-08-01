#include <iostream>
#include "LeetCodeHot100_094.h"

vector<int> Solution094::inorderTraversal(TreeNode* root)
{
	if (root != nullptr)
	{
		inorder(root);
	}
	return _inorder;
}

void Solution094::inorder(TreeNode* node)
{
	if (node->left != nullptr)
	{
		inorder(node->left);
	}
	_inorder.push_back(node->val);
	if(node->right != nullptr)
	{
		inorder(node->right);
	}
}