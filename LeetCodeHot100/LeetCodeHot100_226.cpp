#include <stack>
#include "LeetCodeHot100_226.h"
using std::stack;

TreeNode* Solution226::invertTree(TreeNode* root)
{
	if (root == nullptr)
	{
		return root;
	}
	stack<TreeNode*> stack;
	stack.push(root);
	while (!stack.empty())
	{
		// 交换左右孩子
		auto node = stack.top();
		TreeNode* temp = node->left;
		node->left = node->right;
		node->right = temp;
		// 自身出栈
		stack.pop();
		// 左右孩子入栈
		if (node->left != nullptr)
		{
			stack.push(node->left);
		}
		if (node->right != nullptr)
		{
			stack.push(node->right);
		}
	}
	return root;
}